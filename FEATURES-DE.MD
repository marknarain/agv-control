# Erklärungen der einzelnen Module und Funktionen

Derzeit besitzt dieses Projekt Funktionen für folgende Hardware-Komponenten:  
- **Motors**  
- **LED**  
- **Horn**  
- **LCD Display**  
- **WiFi Access Point (AP)**  
- **Webserver**  
- **Rotary Switch**  

---

## Modul "motors"

Mithilfe dieses Moduls kann man die Motoren des AGV's steuern. Bisher implementierte Funktionen:  

- **motor_init**:  
  Initialisiert die Pins der beiden Schrittmotoren.  

- **update_motor_config**:  
  Setzt den Zustand der Motoren, um deren Drehrichtung zu steuern.  

- **drive**:  
  Bewegt die Motoren um einen Schritt, falls aktiviert. Die Richtung wird zuvor über **update_motor_config** festgelegt.  

- **drive_ramp**:  
  Nutzt die **drive**-Funktion, reduziert jedoch die Pausenzeit zwischen den Schritten, um das Gefährt zu beschleunigen.  

---

## Modul "LED"

Dieses Modul steuert die RGB-LED.  

- **led_init**:  
  Konfiguriert die Pins der RGB-LED und deaktiviert diese.  

- **led_set_rgb**:  
  Setzt die RGB-LED auf eine Farbe basierend auf den übergebenen Parametern.  

- **update_led_color**:  
  Schaltet die LED auf eine vordefinierte Farbe, abhängig vom übergebenen Zustand.  

---

## Modul "Horn"  

Dieses Modul ermöglicht die Steuerung des Horns, um Töne auszugeben.  

- **horn_init**:  
  Initialisiert die benötigten Pins und setzt alle Statusvariablen zurück.  

- **horn_on**:  
  Aktiviert das Horn, indem der entsprechende Pin auf HIGH gesetzt wird.  

- **horn_off**:  
  Deaktiviert das Horn, indem der entsprechende Pin auf LOW gesetzt wird.  

- **update_horn**:  
  Steuert das Horn basierend auf dem aktuellen Zustand und der Dauer des Tons.  
  **Parameter:**  
  - `horn_state` *(int)*: Zustand des Horns (1 = aktiv, 0 = inaktiv).  
  - `honk_time` *(int)*: Dauer des Tons in Millisekunden.  

**Hinweis:**  
Das Horn wird automatisch deaktiviert, sobald die angegebene Zeit abgelaufen ist.  

---

## Modul "LCD Display"  

Dieses Modul steuert das LCD-Display und ermöglicht das Initialisieren, Löschen und Drucken von Text oder Zahlen auf dem Display.

- **lcd_init**:  
  Initialisiert das LCD-Display, schaltet die Hintergrundbeleuchtung ein und setzt den Cursor auf die oberste linke Position (0,0).  

- **lcd_clear**:  
  Löscht den gesamten Inhalt des Displays.  

- **lcd_print (int row, int col, const char* text)**:  
  Druckt den übergebenen Text auf das LCD an der angegebenen Position `(row, col)`.  
  **Parameter:**  
  - `row` *(int)*: Die Zeile, in der der Text angezeigt werden soll (0 oder 1).  
  - `col` *(int)*: Die Spalte, in der der Text angezeigt werden soll (0 bis 15).  
  - `text` *(const char*)*: Der Text, der angezeigt werden soll.  

- **lcd_print (int row, int col, int number)**:  
  Druckt eine Zahl auf das LCD an der angegebenen Position `(row, col)`.  
  **Parameter:**  
  - `row` *(int)*: Die Zeile, in der die Zahl angezeigt werden soll (0 oder 1).  
  - `col` *(int)*: Die Spalte, in der die Zahl angezeigt werden soll (0 bis 15).  
  - `number` *(int)*: Die Zahl, die angezeigt werden soll.   

---

## Modul "WiFi Access Point (AP)"  

Dieses Modul ermöglicht das Einrichten eines WiFi Access Points (AP) und die Bereitstellung der IP-Adresse des AGV (Automated Guided Vehicle).

- **wifi_init**:  
  Initialisiert den WiFi Access Point (AP) mit dem angegebenen Namen und Passwort. Die Funktion setzt den WiFi-Modus auf `softAP` und erstellt ein Netzwerk. Die IP-Adresse des AGV wird gespeichert.  
  **Parameter:**  
  - `wifi_name` *(const char*)*: Der Name des WiFi-Netzwerks (SSID).  
  - `wifi_pwd` *(const char*)*: Das Passwort für das WiFi-Netzwerk.  

- **ip_string**:  
  Gibt die IP-Adresse des AGV als String zurück. Die IP-Adresse wird aus den vier Oktetten der `IPAddress`-Struktur formatiert und in einen dynamisch allokierten String konvertiert.  
  **Rückgabewert:**  
  - `char*`: Der IP-Adresse-String im Format `xxx.xxx.xxx.xxx` (dynamisch allokiert).  

---

## Modul "Webserver"  

Dieses Modul richtet einen Webserver ein, der HTTP-Anfragen verarbeitet, um verschiedene Aktionen wie das Steuern der RGB-LED, die Bewegung des AGV und das Horn auszulösen.

- **start_webserver**:  
  Startet den Webserver und definiert die Endpunkte für die Steuerung der RGB-LED, der Motoren und des Horns. Bei Anfragen an bestimmte URLs werden die entsprechenden Aktionen ausgeführt.  
  **URLs und ihre Funktionen:**  
  - `/`: Zeigt die Startseite des Webservers an, die HTML-Seite (`index_html`) wird zurückgegeben.  
  - `/red`, `/yellow`, `/green`, `/cyan`, `/blue`, `/pink`, `/ledoff`: Steuert die RGB-LED und setzt die LED auf die entsprechende Farbe oder schaltet sie aus.  
  - `/forward`, `/left`, `/right`, `/back`: Steuert die Bewegung des AGV, indem die Richtung der Motoren gesetzt wird.  
  - `/off`: Stoppt die Motoren und setzt den Hornstatus auf aus.  
  - `/HORN`: Aktiviert das Horn.  

- **not_found**:  
  Wird aufgerufen, wenn eine nicht unterstützte URL angefragt wird, und sendet eine 404-Fehlermeldung zurück.

- **get_led_state_webserver**:  
  Gibt den aktuellen Zustand der RGB-LED zurück (Farbe, die aktuell angezeigt wird).  

- **get_button_webserver**:  
  Gibt den aktuellen Zustand des Motors zurück, z. B. die Richtung, in die das AGV fahren soll.  

- **get_horn_state_webserver**:  
  Gibt den aktuellen Zustand des Horns zurück (ob es aktiv ist oder nicht).

---

## Modul "Rotary Switch"  

Dieses Modul steuert den Rotationsschalter und liest die Position des Schalterwerts basierend auf den Pins RE1 und RE2. Es erkennt, in welche Richtung der Schalter gedreht wird und gibt die aktuelle Position zurück.

- **rotary_switch_init**:  
  Initialisiert den Rotary Switch, setzt die Startposition des Schaltsystems auf einen Wert in der Mitte des Bereichs und konfiguriert die Pins für die Eingänge RE1 und RE2. Die Ausgangsposition beginnt bei einem Wert, der ein Vielfaches von 24 ist, um eine kontinuierliche Zählung zu ermöglichen.

- **get_rotary_switch_position**:  
  Liest die aktuellen Zustände der Pins RE1 und RE2. Wenn eine Änderung an RE1 erkannt wird, wird die Drehrichtung anhand des Zustands von RE2 bestimmt (im Uhrzeigersinn oder gegen den Uhrzeigersinn). Die Position wird entsprechend aktualisiert. Am Ende gibt die Funktion die aktuelle Position des Rotary Switch zurück, die auf einen Bereich von 0 bis 23 begrenzt ist.

  **Parameter:**  
  - Keine
  
  **Rückgabewert:**  
  - Die Position des Rotary Switch, normiert auf 0 bis 23.
