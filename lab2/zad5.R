library(tidyverse)

df <- read_delim('wykres.csv', ";")

df %>% ggplot(aes(x = n, y = ratio)) + 
       geom_point() +
       theme_minimal() +
       labs(x = "n", 
            y = expression(paste(tau(n) / n ^2)))

ggsave("wykres.png")
