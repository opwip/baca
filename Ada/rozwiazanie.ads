package Rozwiazanie is

task type Przystan(MAX, WYSTARCZY : Positive) is
  entry Kasa(cena : in Integer; bilet: out Integer);
  entry Wejdz;
  entry Zejdz;
end Przystan;

end Rozwiazanie;