#include <stdio.h>
// Punkte gesammelt ausdrucken, wir verwenden es merhmals
void gesammt_Punkte();

int main(){
    char abgabeTyp; 
    // speicher für Typ der Note, die wir eintragen, am Anfang nicht deklariert, damit der While zummindest einmal geführt wird
    double zwischentest = 0;
    double abschlusstest = 0;
    double ubungsbeispiel = 0;
    double erreichbarepunkte = 0;
    // alle Typs und erreichbare Punkte sind am Anfang auf 0 deklariert, damit gesamt_Punkte erst mit 0 gedrückt wird 
    double gesamtProzent; // für Prozent der erreichbare Punkte
    double gesamtPunkte; // für gesammelte Punkte
    int abschlusstestNummer = 0; //Nummer von Abschlusstest, die bisher gemacht wurden (wichtig, weil nicht mehr als 1 sein soll)
    gesammt_Punkte(zwischentest, abschlusstest, ubungsbeispiel, erreichbarepunkte);
    while (abgabeTyp != '=') // Programm macht weiter bis wir = eintragen
    {
        double note;
        (printf("Typ:\n"));
        scanf("%s", &abgabeTyp);
        if (abgabeTyp == '=')
        {
            break; //wenn =, dann sofort aus von while
        }
        printf("Punkte:"); // damit User die Punkte eintragen kann
        scanf("%lf", &note);
            if (abgabeTyp == 'z'){
            if (note<0.00) // if Note aus dem Bereich
            {
                printf("\nungueltiger Bereich: min 0.00, max 10.00");
                
            } else if (note>10.00) // if Note aus dem Bereich
            {
                printf("\nungueltiger Bereich: min 0.00, max 10.00");
            }
            else { // wenn richtig, dann: 
                zwischentest += note;
                erreichbarepunkte += 10.00;           
            }}

            if (abgabeTyp == 'a'){
            if (note<0.00) // if Note aus dem Bereich
            {
                printf("\nungueltiger Bereich: min 0.00, max 70.00");
                
            } else if (note>70.00) // if Note aus dem Bereich
            {
                printf("\nungueltiger Bereich: min 0.00, max 70.00");
            }
            else if(abschlusstestNummer==0){ //wenn richtig und es noch der ersten Test dann: 
                abschlusstest = note;
                erreichbarepunkte += 70;
                abschlusstestNummer++;
            }
            else{ //wenn es schon ein Test gab, dann aktualisieren wir die Note
                abschlusstest = note;
            }}

            if (abgabeTyp == 'u'){ 
            if (note<0.00) // if Note aus dem Bereich
            {
                printf("\nungueltiger Bereich: min 0.00, max 0.50");
                
            } else if (note>0.50) // if Note aus dem Bereich
            {
                printf("\nungueltiger Bereich: min 0.00, max 0.50");
            }
            else { // Summieren von Note
                ubungsbeispiel += note;
            }
            if (ubungsbeispiel > 10) // wenn es mehr als 10 ist, dann bleibt die gesammte Note aus Übungen bei 10 bleiben
            {
                ubungsbeispiel=10;
            }
            }
        gesammt_Punkte(zwischentest, abschlusstest, ubungsbeispiel, erreichbarepunkte); 
        // einmal ausdrücken die gesammte Punkte bisher
    }
    //nächsten Code passiert nur, wenn Abgabe Typ gleich = war, hier kümmern wir uns um die richtige Note.
        if (abschlusstest + zwischentest <= 0) // alles 0? dann folgendes:
    {
            gesamtPunkte = 0;
            gesamtProzent = 0;
            printf("Gesamtpunkte absolut: %.2lf\n", gesamtPunkte);
            printf("Gesamtpunkte %%: %.2lf %%\n", gesamtProzent);
            printf("Note: 0");
    }
        else if (abschlusstest + zwischentest < (0.5499999*erreichbarepunkte)) 
        // 0.54999 gibt uns die richtige Antwort, sonnst wird 55 als 5 interpretiert(C?). 549999 ist auf jeden Fall genug genau
        // Abschluss und zwischen test nicht 55% oder mehr? dann Übungen kommen nicht dazu
        {
            gesamtPunkte = zwischentest + abschlusstest;
            gesamtProzent = (gesamtPunkte/erreichbarepunkte)*100;
            printf("Gesamtpunkte absolut: %.2lf\n", gesamtPunkte);
            printf("Gesamtpunkte %%: %.2lf %%\n", gesamtProzent);
            printf("Note: 5");

        }
        else{
        // für die andere Fälle kommt alles normal dazu
            gesamtPunkte = zwischentest + abschlusstest + ubungsbeispiel;
            gesamtProzent = (gesamtPunkte/erreichbarepunkte)*100;
            printf("Gesamtpunkte absolut: %.2lf\n", gesamtPunkte);
            printf("Gesamtpunkte %%: %.2lf %%\n", gesamtProzent);
            if (gesamtProzent<67)
            {
                printf("Note: 4");
            } else if (gesamtProzent<78)
            {
                printf("Note: 3");
            } else if(gesamtProzent<89){
                printf("Note: 2");
            } else{
                printf("Note: 1");
            }}
    return 0;
}

void gesammt_Punkte(double zwischentest, double abschlusstest, double ubungsbeispiel, double erreichbarepunkte) {
    printf("\nZT Punkte: %.2lf\n", zwischentest);
    printf("AT Punkte: %.2lf\n", abschlusstest);
    printf("UE Punkte: %.2lf\n", ubungsbeispiel);
    printf("Erreichbare Gesamtpunkte: %.2lf\n", erreichbarepunkte);
    }
