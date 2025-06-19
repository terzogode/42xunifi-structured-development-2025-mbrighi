# Movie Watchlist

## Requisiti principali

- Leggere/scrivere file CSV con 6 campi: ID, titolo, genere, visto, voto, data
- Validazione righe: ignorare righe malformate senza crash
- Gestire fino a circa 1000 film in memoria
- Menu con operazioni: lista, ricerca, aggiunta, modifica, cancellazione, statistiche, salva/esci

## Strutture dati

- `Movie`: rappresenta un film, con ID, titolo, genere, flag visto, voto e data visione
- `Watchlist`: array dinamico di `Movie`, con dimensione, capacità e massimo ID

## Funzioni principali

- `load_watchlist`: carica da file, valida e ignora righe errate
- `save_watchlist`: scrive dati aggiornati nel file
- `add_movie`: aggiunge un nuovo film con ID univoco
- `mark_watched`: aggiorna flag visto, voto e data
- `update_movie`: modifica titolo o genere
- `delete_movie`: elimina un film
- `list_movies`, `search_movies`, `filter_by_watched`: per visualizzazione e ricerca
- `print_statistics`: mostra dati statistici sui film

## Gestione errori

- Righe con dati non validi vengono ignorate con warning su stderr
- Input da utente validati e richiesti nuovamente se errati

