# Progetto: Community Digital Library

## Obiettivo

Realizzare un'applicazione a linea di comando per gestire un catalogo di libri della biblioteca, fornito in un file `.txt`. L'utente potrà cercare libri per titolo o autore.

---

## Struttura del programma

### Strutture dati

- `t_book`: rappresenta un singolo libro con ID, titolo e autore
- `t_library`: contiene un array di puntatori a `t_book` e tiene conto del numero totale

### Funzionalità previste

1. **Caricamento del file**
	- Apertura del file da linea di comando
	- Parsing delle righe valide
	- Ignora righe malformate

2. **Interazione utente**
	- Scelta tra ricerca per titolo o autore
	- Input sensibile al testo (case-insensitive)
	- Messaggi chiari in caso di errori o risultati

3. **Ricerca**
	- Confronto dei campi `title` o `author` con una sottostringa inserita
	- Ignora spazi vuoti e lettere maiuscole/minuscole

4. **Pulizia**
	- Libera memoria allocata