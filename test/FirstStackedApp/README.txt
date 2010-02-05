Applicazione di prova per la creazione di una wizard STATICA (cioè non creata dinamicamente a partire dal file di configurazione xml)

Come usare l'appliacazione:
Come prima cosa è necessario avere installato e configurato correttamente l'ambiente di sviluppo per Symbian 3rd Edition Feature Pack 1. Per far questo bisogna:
-> installare le SDK per il Symbian;
-> installare le Qt "sopra" le SDK;
-> installare l'IDE Carbide.c++
-> configurare Carbide.c++ (dirgli dove sono le qt)
-> pregare che vada tutto

per fare ciò basta seguire attentamente la guita quì presente: http://library.forum.nokia.com/ -> "S60 3rd Edition C++ Developer's Library v1.1"

Una volta installato e configurato l'ambiente si può procedere creando una cartella chiamata "FirstStackedApp" nel workspace di Carbide.c++ e copiandoci dentro i file contenuti nella cartella "prj".
A questo punto si può avviare Carbide.c++ ed importare il progetto. Per far questo basta fare File->Import..., selezionare "Qt Project", selezionare il file FirstStackedApp.pro (descrittore del progetto) ed aprire il progetto. Comunque anche questa procedura è spiegata al link sopra indicato.
Sempre li trovate la procedura dettagliata per fare il build dell'applicazione (per emulatore e per device) e per eseguire l'applicazione.
Se non avete pezza di aprire il progetto, e preferite vedere l'applicazione girare su un Nokia (o sull'emulatore se rovate il modo di installarci un'app), nella cartella "sis" vi ho messo direttamente gli installer per il device (ma quanto sono bravo??). 

Descrizione dell'applicazione:
L'applicazione mi è servita solo per capire un pò in dettaglio come funzionano le Qt e per sviluppare un semplice esempio di wizard statica, per poi ragionare su come renderla dinamica. Probabilmente ho sbagliato tutto.

L'applicazione è composta da una main window (FirstStackApp.h e FirstStackApp.cpp) che non è altro che una finestra con la lista delle azioni disponibili (di cui per il test solo la prima è implementata).
L'idea è che la lista di "bottoni" per accedere alle varie azioni (e le relative wizard) sarà poi generata dinamicamente in base al file xml di configurazione.

Cliccando sul bottone "Action1" viene visualizzata la wizard relativa alla Azione 1 (action1widget.h e action1widget.c++). A dispetto del nome questa classe (e sua implementazione) non rappresenta una particolare wizard per una particolare azione, bensì una wizard generica. Essa infatti contiene la definizione del solo layout "esterno" della wizard (e cioè i bottoni "Close", "Next" e "Pre"). Quello che caratterizza una particolare wizard (in questa particolare implementazione dell'idea.. ancora da vedere se poi va bene per i nostri scopi) sono gli step di cui è composta, che sono a loro volta definiti in classi (e implementazioni) separate.

In particolare per l'esempio che ho utilizzato gli step sono 3:
- uno step descrittivo (descriptionstep.h e descriptionstep.cpp) composto da un unico label contenente del testo (per la descrizione dell'attività ad esempio);
- uno step per l'inserimento di campi testuali (simpletextstep.h e simpletextstep.cpp) composto da un label ed una serie di textbox per l'inserimento di dati;
- uno step per la selezione di opzioni (simpleoptionstep.h e simpleoptionstep.cpp) composto da una serie di radio option per la selezione di qualche parametro

Premendo i tasti "next" e "pre" si può navigare tra i vari wizard, premendo il tasto "Close" si torna al menu delle azioni. 
Non ho ancora implementato/pensato ad un modo per raccogliere i dati al termine della wizard, ma guardando un pò in giro la cosa non dovrebbe essere difficile (neanche una volta che la wizard è dinamica e cioè quando non si sa a priori che campi ci saranno).

Come rendere il tutto dinamico.
Nello sviluppo della wizard ho cercato di rimanere il più modulare possibile, così da poter ragionare sulle possibili soluzioni per rendere la wizard dinamica configurabile tramite il file di configurazione.

La mia idea è la seguente:
Una wizard è rappresentata da una classe generica, che nell'esempio sopra descritto è "Action1Widget" (si lo so il nome è sbagliato, si riferisce all'azione1, ma quando l'ho creata non sapevo bene cosa stavo facendo :P). Questa rappresenta una wizard generica e cioè una finestra con i bottoni per la navigazione (next, pre, una barra di avanzamento.. insomma tutto ciò che riguarda la navigazione tra step). Questa classe, tra le altre cose, contiene la lista di step che caratterizzano la particolare wizard (cioè un array di puntatori agli oggetti che definiscono gli step).
Una particolare wizard (relativa ad una particolare azione) è infatti caratterizzata dagli step di cui è composta; nell'esempio sopra esposto, i tre step di descrizione, inserimento dati e opzioni.

L'idea per gli step invece è la seguente: come abbiamo detto ogni step è di un particolare tipo.. ad esempio, il primo step dell'esempio è uno step descrittivo, quindi composto solo da un label; il secondo è di inserimento dati semplici e quindi può avere solo una lista di textbox (magari con un label per ognuno).. e così via. Questi step ovviamente devono essere definiti a priori, AKA le classi che li definiscono devono essere definiti a priori.

Il funzionamento del tutto potrebbe quindi essere qualcosa del genere:
prima di tutto il parsing del file di configurazione, ricavando quindi quali sono le azioni disponibili e per ognuna quali sono gli step che le compongono.
Questo vuol dire che dal file ricaviamo, per ogni azione:
- che tipo di step contiene; nell'esempio di prima: 1° -> descriptionstep, 2° -> simpletextstep, 3° simpleoptionstep. In questo modo l'app mobile può creare l'oggetto Action1Widget (che non si chiamerà così :P) ed inizializzare la sua lista di step con gli oggetti corretti.
- come sono fatti i vari step. Nell'esempio di prima: 1° -> il label aveva come testo il lorem ipsum; 2° -> il numero di textbox da creare (ed eventualmente il testo dei label associati); 3° -> il numero di opzioni da creare ed il testo dei label ad esse associati.

In questo modo i costruttori dei vari step (che entrano in gioco quando viene inizializzata la lista al punto precedente), sanno come creare il proprio step. Ad esempio, nell'inizializzazione della lista invochiamo il costruttore del primo step passandogli il testo del label; per il secondo step al construttore passiamo il numero di textbox e un array di stringhe che contiene i label etc... poi i costruttori, essendo fissi per tipo di step, sanno cosa fare :)

L'unico punto che mi è ancora oscuro è la generazione del menu delle azioni. La creazione dinamica dei bottoni è ok, facilissimo, ma quello che non so ancora bene come fare è come connettere dinamicamente gli eventi clicked() dei bottoni creati con gli slot per visualizzare la giusta wizard.
Ci penserò domani. :P

L'idea è questa.. che ne pensate?
Poichè sono un pò provato dai mille progetti che sto facendo, potrei aver scritto solo una marea di stronzate... :( tra l'altro perdonate l'italiano ma andavo di fretta :)
