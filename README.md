# Moje učenje C-ja pri predmetu P2

# 🛠️ nov_izpit & npp – Linux skripte za C projekte

Ta repozitorij vsebuje dve uporabni skripti za avtomatizacijo priprave nalog in testnih datotek:

- `nov_izpit`: ustvari 3 `.c` (prva.c, druga.c, tretja.c) datoteke s C boilerplate-om in 3 `.in` testne datoteke.
- `npp`: omogoča zagon Notepad++ iz ukazne vrstice.

---

##  Namesti skripto globalno

```
sudo cp nov_izpit /usr/local/bin/nov_izpit
sudo chmod +x /usr/local/bin/nov_izpit

sudo cp npp /usr/local/bin/npp
sudo chmod +x /usr/local/bin/npp
```

### Preveri delovanje npp

```
npp test.txt
```
Moralo bi se ti odpreti okno od Notepad++ z vprašanjem ali želiš ustvariti datoteko test.txt
(Notepad++ mora biti nameščen v /mnt/c/Program Files/Notepad++, drugače ustrezno popravi npp skripto s pravilno lokacijo)

### Preveri delovanje nov_izpit
