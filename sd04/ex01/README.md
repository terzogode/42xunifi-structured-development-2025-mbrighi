# Expense Tracker - Progetto Analisi Spese

## Obiettivo
Questo programma legge un file CSV contenente spese personali, ne analizza e filtra i dati validi, e genera un riepilogo dettagliato.

## Funzionalità
- Parsing di file CSV con controllo di errori e formato
- Filtraggio per categoria (case-insensitive)
- Filtraggio per intervallo di date (YYYY-MM-DD)
- Calcolo di statistiche (totale, media, per categoria)
- Gestione di massimo 1000 spese in memoria

## Struttura del Progetto
### Header file unico: `expense_tracker.h`
Contiene:
- Strutture dati per gestire spese e lista spese
- Prototipi di tutte le funzioni principali
- Commenti per facilitare la comprensione

### Approccio al parsing
- Ogni riga è separata da virgole
- Vengono ignorate righe con:
	- Date non valide
	- Importi negativi, zero, non numerici
	- Campi mancanti

### Gestione della memoria
- Le stringhe categoria e descrizione sono allocate dinamicamente
- Alla fine del programma, viene liberata tutta la memoria

## Esempio di linea valida:
