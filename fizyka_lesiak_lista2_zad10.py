# Importujemy biblioteki
# Ta tutaj jest koks, robi cuda na wektorach i jest napisana w C, także nie ma że Python wolny
import numpy as np 

# Jaka sama nazwa wskazuje, szpej do robienia wykresów, też jest sztos
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter  

v = 1
delta_v = 0.2
dt = 50e-3
n = 100
ext = 30

# Generalny zamysł jest taki, że robimy oś ext=30 razy dłuższą niż przestrzeń pomiędzy dwoma ścianami,
# wyobrażamy sobie, że piłka porusza się ruchem jednostajnym wzdluż tej prostej i wyliczamy jej pozcję z Gaussowym rozkładem 
# a następnie mapujemy to do odcinka między ścianami.
# Możnaby to robić na jakiejś chmurze losowych cząstek (ale to by było złożone obliczeniowo) albo
# rozwiązując fancy równania (ale do tego nie mam mózgu)

# tworzymy wektor (tablice) liczb od 0 do ext, mającą ext*n elementów, to jest ta wyobrażona prosta
x = np.linspace(0, ext, ext*n)

# inicjujemy libkę do wykresów
fig, ax = plt.subplots()

# miejsca do wyświetlania tekstu
time_text = plt.text(0.9, 5.1, 't=0s', fontsize=15)
plt.text(0, 5.1, f'$v={v} \pm {delta_v} \\frac{{m}}{{s}}$', fontsize=15)

# ustawiamy na stałę skalę w Y
ax.set_ylim(0, 5)

ax.set_xlabel("Położenie [m]")
ax.set_ylabel("Gęstość prawdopodobieństwa [$m^{-1}$]")
  
def update(t):
    time_text.set_text(f't={t:.2f}s')
    
    # niepewność położenia
    delta_x = delta_v * t 
    # położenie w idealnym wypadku
    center_x = v * t 

    # obliczamy rozkład Gaussa dla każdego elementu w tablicy x
    extended_probability = 1 / (delta_x * np.sqrt(2 * np.pi)) * np.exp(-0.5 * ((x - center_x) / delta_x)**2)
    
    # tutaj się dzieje główne sztuczkarstwo, dzielimy tablicę na ext=30 tablic po n=100 elementów 
    prob_wraped = extended_probability.reshape((ext, n))

    # obracamy tablice o nieparzystych numerach (bo piłka toczy się w przeciwnym kierunku)
    mask = np.arange(1, 30, 2)
    prob_wraped[mask] = np.flip(prob_wraped[mask],axis=1)

    # sumujemy prawdopodobieństwa z ext=30 tablic
    prob = np.sum(prob_wraped, axis=0)

    # czyścimy wykres
    ax.collections.clear()
    # rysujemy nowe wypełnienie
    ax.fill_between(np.linspace(0, 1, n), 
                    prob, 
                    facecolor='lightgreen', 
                    alpha=0.8)

# checmy obliczyć klatki od t=0 do t=5 z krokiem 50ms
ts = np.arange(0, 5, dt)

# funkcja która wykonuje update dla wszystkich zadanych czasów
ani = FuncAnimation(fig, update, ts, interval=dt)

# następnie zapisuje do GIFa
writer = PillowWriter(fps=1/dt)  
ani.save("physics.gif", writer=writer)  

# i również wyświetla użyszkodnikowi
plt.show()
