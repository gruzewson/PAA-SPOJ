BISORT - Własne porządki
Jaś, który był prawdziwym molem książkowym, postanowił wprowadzić własne porządki w swoim bogatym księgozbiorze liczącym n <= 500000 książek. "Każda książka musi być na swoim miejscu!" - pomyślał rezolutny Jaś, uśmiechając się pod nosem...
Ponumerował przeto Jaś każdą książke nadając jej unikatowy numer (0 <= numer <= 109) i poukładał je na półce w przypadkowej kolejności. Następnie książkę o numerze k1-tym w porządku nierosnącym zamienił Jaś z ostatnią książka na półce. Dalej, wybrał Jaś książkę o numerze k2-tym w porządku nierosnącym z pozostałych książek (poza ostatnią) i zamienił ją z przedostatnią książką na półce, itd... Aby uniknąć pomyłki, Jaś od czasu do czasu spisuje kolejne numery książek na półce. "Nikt nie zgadnie mojego własnego porządku" - ucieszył się Jaś. Spróbuj rozszyfrować porządek Jasia! Zakładać będziemy, że 1 <= ki <= n - i + 1.

Dane wejściowe składają się z 15 testów, podzielonych na trzy grupy:

testy 1-5: liczba książek n <= 10000, 1 <= ki <= 2,
testy 6-10: liczba książek n <= 10000, 1 <= ki <= n - i + 1,
testy 11-15: liczba książek n <= 500000, 1 <= ki <= n - i + 1.
Wejście
W pierwszej linii na wejściu podana będzie ilość książek n. W drugiej linii podane będą numery książek oddzielone spacjami (w porządku przypadkowym), w trzeciej linii podane będą wartości k1, k2, ..., kn. Wreszcie w czwartej linii podane będą numery kroków (przestawień jednej książki), po której Jaś zapisuje stan na półce. Zakładamy, że ostatnią wartością w czwartej linii będzie n.

Wyjście
Na wyjściu w kolejnych liniach należy wypisać wszystkie te stany półki, które odnotował Jaś.

Przykład 1
Wejście:
10
318 428 564 190 369 272 551 620 98 517
1 2 1 2 2 2 2 2 1 1
2 7 8 9 10
Wyjście:
318 428 564 190 369 272 98 517 551 620
190 98 517 272 318 369 428 564 551 620
517 98 190 272 318 369 428 564 551 620
98 517 190 272 318 369 428 564 551 620
98 517 190 272 318 369 428 564 551 620
Przykład 2
Wejście:
10
2432 1583 5523 4560 2903 1299 1933 3813 721 1072
8 5 5 5 1 4 1 2 1 1
1 4 5 10
Wyjście:
2432 1583 5523 4560 2903 1072 1933 3813 721 1299
721 3813 5523 4560 2903 1072 1583 1933 2432 1299
721 3813 1072 4560 2903 5523 1583 1933 2432 1299
721 3813 2903 4560 1072 5523 1583 1933 2432 1299
