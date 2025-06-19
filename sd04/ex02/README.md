# Contact Manager - Progettazione

## Obiettivo
Realizzare un semplice gestore di contatti da console, capace di leggere/salvare contatti da un file CSV, gestire errori di formato e offrire funzionalità di ricerca, modifica, aggiunta, cancellazione e salvataggio dei dati.

## Struttura dei dati

Ogni contatto è descritto con i seguenti campi:

- **ID** (intero positivo, univoco)
- **Name** (non vuoto)
- **Phone** (deve contenere almeno una cifra, possono esserci simboli `+`, `-`, `(`, `)`)
- **Email** (formato valido con `@` e almeno un punto nella parte dominio)
- **City** (non vuota)
- **Address** (può essere vuota)

I contatti sono memorizzati in una lista dinamica (`t_contact_list`) in memoria.

## Validazioni richieste

| Campo   | Regola |
|--------|--------|
| ID     | Intero positivo, non duplicato |
| Name   | Non vuoto dopo il trim         |
| City   | Non vuoto dopo il trim         |
| Phone  | Almeno una cifra, simboli ammessi |
| Email  | Deve contenere `@`, dominio con `.` |
| Address| Può essere vuoto               |

Le righe non valide nel CSV vengono ignorate con un warning.

---

## Menu Principale

Dopo il caricamento del file, l’utente può:

1. 📋 Elencare tutti i contatti
2. 🔍 Cercare per nome o città
3. ➕ Aggiungere un contatto
4. 📝 Modificare un contatto
5. ❌ Eliminare un contatto
6. 💾 Salvare ed uscire

---

## Gestione file

- Il file CSV viene letto riga per riga.
- In scrittura si usa un file temporaneo (`filename.tmp`) e poi si fa `rename()`.
- Errori di scrittura devono essere gestiti con messaggi chiari.

---
