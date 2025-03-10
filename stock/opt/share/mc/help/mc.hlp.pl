[Contents]
  OPISDESCRIPTION
  OPTIONSOPTIONS
  OpisOverview
  Obsługa myszyMouse Support

  KlawiszeKeys
    Klawisze różneMiscellaneous Keys
    Panel KatalogówDirectory Panels
    Quick searchQuick search
    Linia PowłokiShell Command Line
    Podstawowe klawisze ruchuGeneral Movement Keys
    Linia wejściowa klawiszyInput Line Keys

  Linia menuMenu Bar
    Lewe i prawe menuLeft and Right Menus
      Tryby wyświetlania (Listing modes)Listing Format...
      Porządek sortowania (Sort order...)Sort Order...
      Filtry (Filter...)Filter...
      Odśwież (Reread)Reread
    Menu plików (File menu)File Menu
      Szybka zmiana katalogów (Quick cd) M\-cQuick cd
    Menu komend (Command Menu)Command Menu
      Drzewo katalogów (Directory Tree)Directory Tree
      Znajdź plik (Find File)Find File
      Panel zewnętrznyExternal panelize
      HotlistHotlist
      Edycja rozszerzeń pliów (Edit Extension File)Edit Extension File
      Prace w tle (Background jobs)Background Jobs
      Edycja menu użytkownika (Edit Menu File)Edit Menu File
    Menu opcji (Options Menu)Options Menu
      KonfiguracjaConfiguration
      Wygląd (Layout)Layout
      Potwierdzanie (Confirmation)Confirmation
      Wyświetlanie znaków (Display bits)Display bits
      Nauka klawiszy (Learn keys)Learn keys
      Wirtualny system plików (Virtual FS)Virtual FS
      Zapisz ustawienia (Save Setup)Save Setup

  Wykonywanie poleceń systemu operacyjnego (Executing operating system commands)Executing operating system commands
    Wbudowana komenda cd (The cd internal command)The cd internal command
    Obsługa makr (Macro Substitution)Macro Substitution
    Obsługa podpowłoki (The subshell support)The subshell support
  ChmodChmod
  ChownChown
  Zaawansowane chown (Advanced Chown)Advanced Chown
  Operacje na plikach (File Operations)File Operations
  Maski kopiowania/przenoszenia (Mask Copy/Rename)Mask Copy/Rename
  Wbudowany podgląd plikówInternal File Viewer
  Wbudowany edytor plikówInternal File Editor
  DokańczanieCompletion
  Wirtualny system plików (Virtual File System)Virtual File System
    System plików FTP (FTP File System)FTP File System
    System plików tar (Tar File System)Tar File System
    Transfer plików pomiędzy systemami plików (FIle transfer over SHell filesystem)FIle transfer over SHell filesystem
    Odzyskiwanie plikówUndelete File System
    EXTernal File SystemEXTernal File System
  Polskie znakiPolskie znaki
  KoloryColors
  Specjalne ustawieniaSpecial Settings
  Baza danych terminali (Terminal databases)Terminal databases

  PLIKIFILES
  DOSTĘPNOŚĆAVAILABILITY
  ZOBACZ TAKŻESEE ALSO
  AUTORZYAUTHORS
  BŁĘDYBUGS
  TŁUMACZENIETŁUMACZENIE
  LicenseLicense
  Okna zapytańQueryBox
  Jak używać pomocyHow to use help
[DESCRIPTION]
OPIS

Midnight Commander jest przeszukiwarką katalogów/menedżerem plików dla systemów Unixopodobnych[OPTIONS]

OPCJE


-a      Wyłącza używanie symboli graficznych przy rysowaniu ramek.

-b      Wymusza wyświetlanie czarno-białe.

-c      Wymusza wyświetlanie w kolorze, zobacz sekcję Kolory żeby zasięgnąć szerszej informacji.

-C arg  Używane do wybierania innego koloru, który ma być obecny w linii poleceń. Format argumentu arg jest opisany w sekcji Kolory.

-d      Wyłącza używanie myszy.

-f      Wyświetla wkompilowane ścieżki, w których Mindnight Commander szuka swoich plików.

-k      Resetuje "miękkie" klawisze do ich standardowych funkcji z termcap/terminfo. Użyteczne tylko przy terminalach HP, kiedy klawisze funkcyjne nie działają.

-l plik Zachowuje logi z serwerów ftp do pliku plik.

-P      Przy zakończeniu programu, Midnight Commander wydrukuje na ekranie katalog, w którym pracowaliśmy na końcu; to w połaczeniu z funkcją napisaną poniżej pozwoli ci na przeglądanie swoich katalogów i automatyczne przejście do tego, w którym byłeś ostatnio (dziękuję Torbenowi Fjerdingstadowi i Sergeyowi za wkład w tę funkcję oraz za kod źródłowy, który wprowadzili w życie).
użytkownicy basha i zsh:

mc ()
{
        MC=$HOME/tmp/mc$$-"$RANDOM"
        %bindir%/mc -P "$@" > "$MC"
        cd "`cat $MC`"
        rm "$MC"
        unset MC;
}

użytkownicy tcsh:
alias mc 'setenv MC `%bindir%/mc -P !*`; cd $MC; unsetenv MC'
        Wiem, że ta funkcja mogłaby być krótsza dla basha i zsh, ale małe cudzysłowy nie zaakceptowały by zawieszenia programu kombinacją C-z.

-s      Włącza tryb powolnego terminala, w którym program nie będzie rysował zbyt obciążających znaków graficznych oraz wyłączy opcję weryfikacji.

-t      Używane tylko jeśli kod był skompilowany przy użyciu S-Langa i terminfo: powoduje, że Midnight Commander będzie używać zmiennej środowiskowej TERMCAP do pokazywania informacji terminala, zamiast informacji w systemowej bazie typów terminali.

-u      Wyłącza używanie równoległej powłoki (ma sens tylko jeśli Midnight Commander był kompilowany z obsługą równoległych powłok).

-U      Włącza użycie jednoczesnego inerpretatora poleceń (ma sens tylko jeśli Midnight Commander był zbudowany z ustawieniem powłoki w tle jako opcji dodatkowej).

-v plik Włącza wbudowany podgląd w celu obejrzenia wybranego pliku plik.

-V      Wyświetla wersję programu.

-x      Wymusza włączenie trybu xterm. Używane kiedy działa się na terminalach wyposażonych w opcje xterm (dwa tryby ekranu i możliwość wysyłania myszą sygnałów wyjścia).

-X, --no-x11
        Do not use X11 to get the state of modifiers Alt, Ctrl, Shift

-g, --oldmouse
        Force a "normal tracking" mouse mode. Used when running on xterm-capable terminals (tmux/screen).

Jeśli wybrano, pierwszy katalog używany jest do wyświetlenia w pierwszym panelu. Drugi wyświetlany jest w drugim panelu.[Overview]
Opis

Ekran Midnight Commandera podzielony jest na cztery części. Prawie cały obszar ekranu zajmują dwa panele. Standardowo przedostatnia od dołu linijka ekranu, przeznaczona jest do wpisywania poleceń, a ostatnia pokazuje klawisze funkcyjne. Najwyższy wiersz jest wierszem menu. Może on być niewidoczny, ale pojawia się zawsze po kliknięciu w najwyższą linię ekranu, albo po wciśnięciu klawisza F9.

Midnight Commander pozwala na oglądanie dwóch paneli w tym samym czasie. Jeden z nich jest panelem aktywnym (podświetlona linia wyboru znajduje się właśnie w nim). Niemal wszystkie operacje wykonuje się na panelu aktywnym. Niektóre operacje, jak np. kopiowanie, zmiana nazwy używają jako domyślnego miejsca docelowego katalogu otwartego w panelu nieaktywnym (nie martw się, zawsze zostaniesz poproszony o potwierdzenie takiej operacji). W celu zasięgnięcia szerszych informacji zajrzyj do działów Panele katalogów, Lewe i prawe menu oraz Menu plików.

Możesz wywoływać dowolne komendy systemowe po prostu wpisując je. Wszystko co piszesz pojawia się w linii poleceń i po naciśnięciu klawisza Enter zostanie wykonane przez Midnight Commandera. Przeczytaj sekcję Linia powłoki i Linia wejściowa klawiszy, żeby nauczyć się więcej na ten temat.

[Mouse Support]
Obsługa myszy

Midnight Commander obsługuje mysz. Moduł ten jest uruchamiany wtedy kiedy korzystasz z terminala xterm(1) (działa nawet wtedy, kiedy łączysz się przez telnet albo rlogin z innym komputerem z terminala xterm) lub jeśli korzystasz z linuksa na konsoli z zainstalowanym serwerem gpm(1).

Kiedy klikniesz lewym przyciskiem na panel z katalogami, plik zostanie wybrany jako aktywny; jeśli klikniesz prawym przyciskiem zostanie on zaznaczony [lub odznaczony - w zależności od jego aktualnego stanu - działanie podobne do klawisza Insert - przyp. tłumacza].

Podwójne kliknięcie w plik spowoduje wykonanie pliku, jeśli jest on wykonywalny, a jeśli rozszerzenie pliku jest rozpoznawane przez Midnight Commander'a i dostępny jest odpowiedni program, jest on uruchamiany.

Możliwe jest również wykonywanie komend przypisanych klawiszom funkcyjnym przez kliknięcie w nie.

Jeśli kliknięcie odbędzie się w rejonie górnej lini panelu z katalogami, zostanie on przewinięty jedną stronę wstecz. Podobnie kliknięcie na dolną ramkę przewija tekst jedną stronę do przodu. Ta opcja klikania w ramki działa również przy przeglądaniu pomocy i przy drzewie katalogów.

Standardowo czas autopowtórzenia przy klikaniu myszą wynosi 400 milisekund. Tę wartość można zmienić edytując plik ~/.config/mc/ini i zmieniając parametr mouse_repeat_rate.

Jeśli używasz Midnight Commandera z obsługą myszy, możesz "przeszczepiać" kawałki tekstów i używać standardowych zastosowań myszki (kopiowanie i wklejanie) za pomocą klawisza Shift.

[Keys]
Klawisze

Niektóre komendy Midnight Commandera wywołuje się kombinacją klawiszy Control (czasem opisywanego jako CTRL lub CTL) lub Meta (opisywanego ALT lub nawet Compose). W tym manualu (pliku pomocy) będziemy używać następujących kombinacji: C-<klawisz> - znaczy: trzymając klawisz Control naciśnij <klawisz>. Więc C-f będzie oznaczać: trzymając Control, naciśnij f.

M-<klawisz> - znaczy, że trzymając klawisz Meta lub alt naciskamy <klawisz>. Jeśli na twojej klawiaturze nie ma ani klawisza Alt ani Meta, naciśnij ESC, puść go i wtedy naciśnij <klawisz> [skutek ten sam, acz jednak użycie trochę mniej przyjemne i bardziej skomlikowane - przyp. tłumacza].

Wszystkie linie wprowadzające Midnight Commandera używają w przybliżeniu tych samych przypisań klawiszy co wersja GNU edytora Emacs.

Jest wiele sekcji mówiących o klawiszach. Ta następująca jest najważniejsza.

Sekcja Menu plikówFile Menu opisuje skróty klawiszowe do komend pojawiających się w menu plików. Ta sekcja zawiera funkcję klawiszy. Większość z tych komend wywołuje jakąś akcję przede wszystkim na jednym lub kilku wybranych plikach.

Sekcja Panele katalogoweDirectory Panels opisuje klawisze, które zaznaczają plik lub pliki jako docelowe do dalszych działań (akcją jest najczęściej jedna z tych przedstawionych w menu plików).

Sekcja Komendy linii poleceń wypisuje listę klawiszy, które są używane do wprowadzania lub edytowania tekstów w wierszu poleceń. Większość z nich kopiuje nazwy, i inne tego typu, z panelu katalogów do linii poleceń (żeby uniknąć ich przepisywania), lub pozwala zwiedzić historię komend linii poleceń.

Klawisze linii wejściowych są używane do edytowania linii na wejściu (przy wpisywaniu). Oznacza, to że stosuje się je zarówno do linii poleceń jak do okien dialogowych.

[Miscellaneous Keys]
Klawisze różne

Jest tu kilka klawiszy, które nie kwalifikują się do żadnej z wymienionych powyżej grup:

Enter. Jeśli jest wpisany jakiś tekst w linii poleceń (na samym dole, pod panelami), to wpisana komenda jest wykonywana. Jeśli nic nie jest wpisane, i linia wyboru jest na jakimś katalogu, Midnight Commander wykonuje komendę chdir(2) (zmiana katalogu) do wybranego katalogu i odświeża zawartość panelu; jeśli linia wyboru jest na pliku wykonywalnym jest on wykonywany. I wreszcie jeśli rozszerzenie pliku zgadza się z obługiwanym przez programy zewnętrzne, które są obsługiwane prze Midnight Commandera, są one wywoływane z owym programem.

C-l. Od nowa rysuje wszystkie informacje okna Midnight Commandera.

C-x c. Uruchamia komendę Chmod dla aktualnego pliku lub zaznaczonych plików.

C-x o. Uruchamia komendę Chown dla aktualnego pliku lub zaznaczonych plików.

C-x l. Uruchamia komendę dowiązywania.

C-x s. Uruchamia komendę miękkiego dowiązywania.

C-x i. Zmienia aktywny panel.

C-x q. Przełacza nieaktywny panel w tryb "quick view".

C-x !. Wykonuje komendę z zewnętrznego panelu.

C-x h. Uruchamia komendę dodawania katalogów do hotlisty.

M-!. Uruchamia komendę filtrowanego podglądu, opisanego w sekcji Podgląd.

M-?. Uruchamia komendę szukania pliku.

M-c. Włącza okno dialogowe quick cd (szybkiej zmiany katalogów)

C-o. Jeśli program jest uruchamiany na konsoli typu Linux lub FreeBSD lub też na konsoli xterm, pokaże wyjście ostatnio wykonywanego programu. Jeśli uruchomiono Midnight Commandera na konsoli type Linux, MC używa zewnętrznego programu (cons.saver) w celu zachowywyania i odzyskiwania informacji na ekranie komputera.

Jeśli użycie trybu powłoki w tle jest wkompilowane, możesz nacisnąć C-o w dowolnej chwili i zostataniesz przeniesiony z powrotem bezpośrednio do głównego okna Midnight Commandera, żeby powrócić do wykonywania aplikacji po prostu naciśnij znów C-o. Jeśli masz zawieszoną aplikację właśnie przez użycie tego triku, nie będziesz mógł "odpalać" innych programów spod Midnight Commandera dopóki nie zamkniesz zawieszonego programu.

Aby dowiedzieć się czegoś na temat polskiech liter w Midnight Commanderze przeczytaj sekcję Polskie litery.

[Directory Panels]
Panel Katalogów

Sekcja opisuje klawisze, które operują na panelu katalogów. Jeśli chcesz wiedzieć jak zmienić panele zobacz sekcję Lewe i prawe menu.

Tab, C-i. Zmienia aktywny panel. Stary panel staje się w tym momencie aktywnym panelem, a aktywny staje się starym. Linia wyboru zmienia swoje położenia do aktywnego panelu.

Insert, C-t. DEPRECATED! Do zaznaczania plików możesz używać klawisza Insert lub C-t. Żeby odznaczyć plik po prostu zaznacz jakiś już zaznaczony.

Insert  to tag files you may use the Insert key (the kich1 terminfo sequence). To untag files, just retag a tagged file.

M-e     to change charset of panel you may use M-e (Alt-e). Recoding is made from selected codepage into system codepage. To cancel the recoding you may select "directory up" (..) in active panel. To cancel the charsets in all directories, select "No translation " in the dialog of encodings.

M-g, M-r, M-j. Używane do wybierania najwyższego, środkowego i najniższego pliku w panelu.

M-t. Przełącza tryb wyświetlania do następnego możliwego. Używając tej opcji łatwo jest przejść szybko z długiego do krótkiego trybu wyświetlania jak również do tego zdefiniowanego przez użytkownika.

C-\ (control-backslash). Pokazuje hotlistę katalogów i zmienia katalog do wybranego przez użytkownika.

+ (plus). Używane do zaznaczania grupy plików. Midnight Commander zapyta o wyrażenie opisującą grupę. Jeśli opcja Shell Patterns jest włączona, typ wyrażeń jest bardzo podobny do tego w powłoce (* dla zera i więcej znaków i ? dla jednego znaku). Jeśli zaś opcja Shell Patterns jest wyłączona, sposób zaznaczania plików jest zgodny z ustawieniami (zobacz ed(1)).

\ (backslash). Używaj znaków "\" do odznaczania grupy plików. Jest to przeciwieństwo klawisza plus.

strzałka do góry, C-p. Przenosi linię wyboru do poprzedniej pozycji w panelu.

strzałka do dołu, C-n. Przenosi linię wyboru do następnej pozycji w panelu.

home, a1, M-<. Przenosi linię wyboru do pierwszej pozycji w panelu.

end, c1, M->. Przenosi linię wyboru do ostatniej pozycji w panelu.

PageDown, C-v. Przenosi linię wyboru jedną stronę do dołu.

PageUp, M-v. Przenosi linię wyboru jedną stronę do góry.

M-o. Jeśli drugi panel jest zwykłym panelem wyświetlającym i w aktywnym panelu stoisz na katalogu, drugi panel będzie pokazywać zawartość akutalnego katalogu (tak jak w Emacsie kombinacja C-o). Jeśli nie stoisz na katalogu zawartością drugiego katalogu stanie się katalog o jedno piętro wyższy od aktualnego.

C-PageUp, C-PageDown. Działa tylko na konsoli typu Linux: wykonuje przejście do katalogu ".." lub do aktualnie wybranego, w zależności od kombinacji.

M-y. Przenosi do poprzedniego katalogu w historii, podobne do kliknięcia myszką. '<'.

M-u. Przechodzi do następnego katalogu w historii, podobne do kliknięcie myszką w '>'.

M-S-h, M-H. Wyświetla historię katalogów, podobne działanie do kliknięcia myszką 'v'.

[Quick search]
Quick search


C-s, M-s. Uruchamia szukanie pliku w katalogu na podstawie jego nazwy. Kiedy szukanie jest aktywne, każde naciśnięcie klawisza doda jeden znak do poszukiwania zamiast wypisania go linii poleceń. Jeśli opcja "Show mini-status" jest włączona, szukany ciąg znaków pojawia się w linii mini-statusu. Kiedy wpisujemy znak, linia wyboru przemieszcza się do następnego pliku zaczynającego się od podanych liter. Klawisze backspace lub del mogą być używane do poprawiania błędów. Jeśli C-s zostanie naciśnięte ponownie, Midnight Commander rozpoczyna szukanie następnego pliku zaczynającego się od podanych znaków.[Shell Command Line]
Linia Powłoki

Ta sekcja opisuje klawisze, które są użyteczne do efektywniejszego wpisywania podczas podawania komend powłoki.

M-Enter. Kopiuje nazwę aktualniego wybranego pliku do linii poleceń.

C-Enter. To samo co M-Enter, działa tylko na konsoli typu Linux.

M-Tab. Wykonuje dokończenie nazw plików, komend, zmiennych, użytkowników, nazw hostów za Ciebie.

C-x t, C-x C-t. Kopiuje nazwy zaznaczonych plików (lub jeśli nie ma zaznaczonych - aktywnego) w aktywnym (C-x t) lub nieaktywnym panelu (C-x C-t) do linii poleceń.

C-x p, C-x C-p. Pierwsza kombinacja kopiuje pełną ścieżkę z aktywnego, a druga z nieaktywnego panelu.

C-q. Komenda 'quote' (cytuj) może być używana do wpisywania do wiersza poleceń znaków, które normalnie przechwytywane są przez Commandera (tak jak znak '+').

M-p, M-n. Używaj tych klawiszy, żeby przeglądać historię komend. M-p wyświetla poprzednią, a M-n następną komendę.

M-h. Wyświetla historię aktualnej linii poleceń.

[General Movement Keys]
Podstawowe klawisze ruchu

Przeglądarka pomocy, podgląd plików i drzewo katalogów używają podobnych klawiszy do przemieszczania. Przez to akceptują dokładnie te same klawisze. Każde z nich z resztą traktują je jako swoje własne.

Niektóre partie Midnight Commandera również używają tych klawiszy, więc niniejsza sekcja może być użyteczna również dla tych partii.

strzałka w górę, C-p. Przechodzi jedną linię wstecz.

strzałka w dół, C-n. Przechodzi jedną linię naprzód.

Page Up, M-v. Przechodzi jedną stronę wstecz.

Next Page, Page Down, C-v. Przechodzi jedną stronę naprzód.

Home, A1. Przechodzi do początku.

End, C1. Przechodzi na koniec.

Przeglądarka pomocy i podgląd plików akceptują następujące klawisze (poza tymi opisanymi powyżej).

b, C-b, C-h, Backspace, Delete. Przechodzi jedną stronę wstecz.

klawisz spacji. Przechodzi jedną stronę naprzód.

u, d. Przechodzi pół strony naprzód lub wstecz.

g, G. Przechodzi do początku lub do końca.

[Input Line Keys]
Linia wejściowa klawiszy

Linie wejściowe (te używane w linii komend i w oknach dialogowych), akceptują następujące klawisze:

C-a. umieszcza kursor na początku linii.

C-e. umieszcza kursor na końcu linii.

C-b, move-left. przenosi kursor o jedną pozycję w lewo.

C-f, move-right. przenosi kursor o jedną pozycję w prawo.

M-f. przesuwa kursor o jedno słowo naprzód.

M-b. przesuwa kursor o jedno słowo wstecz.

C-h, backspace. kasuje poprzedni znak.

C-d, Delete. kasuje znak w miejscu kursora (nad nim).

C-@. wstawia zaznaczenie do kasowanie (patrz następne pozycje).

C-w. kopiuje tekst spomiędzy kursora i zaznaczenia do bufora i usuwa go z linii poleceń.

M-w. to samo co C-w tylko, że nie usuwa tekstu z linii.

C-y. wstawia spowrotem zawartość wyciętego bufora.

C-k. wycina tekst od kursora do końca linii.

M-p, M-n. Używaj tych klawiszy, żeby przeglądać historię komend. M-p wyświetla poprzednią, a M-n następną.

M-C-h, M-Backspace. kasuje jedno słowo wstecz (poprzednie).

M-Tab. Wykonuje dokończenie nazw plików, komend, zmiennych, użytkowników, nazw hostów za Ciebie.



[Menu Bar]
Linia menu

Linia menu uaktywnia się kiedy wciskasz klawisz F9 lub kiedy klikasz myszką na najwyższy wiersz ekranu. Linia menu ma pięć podmenu: "left", "file", command", "options" i "right" (po polsku to jest "lewe", "plik", "komendy", "opcje", "prawe").

Lewe i prawe menu pozwalają ci na modyfikacje wyglądu lewego i prawego panelu katalogowego.

Menu plik pozwala na wykonanie akcji na aktualnym lub zaznaczonych plikach.

Menu komend mieści w sobie możliwe do wykonania akcje, które są dużo bardziej globalne i nie mają związku z aktualnym i zaznaczonymi plikami.

[Left and Right Menus]
Lewe i prawe menu

Wygląd panelu katalogowego może zostać zmieniony poprzez menu left i right.

[Listing Format...]
Tryby wyświetlania (Listing modes)

Tryby wyświetlania są używane do zmienia ustawień przy wyświetlaniu. Dostępne są cztery różne tryby: Full, Brief, Long i User. Tryb "Full" pokazuje nazwę, rozmiar i czas modyfikacji pliku.

Tryb "Brief" pokazuje tylko nazwę pliku i ma dwie kolumny (dzięki temu może pokazywać nawet dwa razy więcej niż inne tryby). Tryb "Long" jest podobny do wyniku polecenia ls -l. Zabiera on szerokość całego ekranu.

Jeśli wybierzesz tryb "user" (użytkownika), będziesz mógł wybrać własny sposób wyświetlania.

Tryb użytkownika musi zaczynać się od określenia wielkości panelu. Może to być "half" (pół) lub "full" (cały) i określa, czy ma być widoczny jeden duży panel na cały ekran czy dwa mniejsze.

Po rozmiarze panelu możesz włączyć tryb dwóch kolumn panelu. Robi się to dodając liczbę "2" do tekstu formatu.

Po tym wpisujesz już nazwy pól z podaniem opcjonalnej wielkości. Wszystkie możliwe pola jakich możesz użyć to:

name    wyświetla nazwę pliku.

size    wyświetla wielkość pliku.

bsize   jest alternatywą dla format size. Wyświetla rozmiar plików, a dla katalogów po prostu wyświetla tekst "SUB-DIR" lub "UP--DIR".

type    wyświetla jednoznakowy opis typu pliku. Ten znak jest taki sam co ten wyświetlany prze komendę ls z flagą -F. Wyświetlana jest gwiazdka dla plików wykonywalnych, ukośnik dla katalogów, małpa (@) dla dowiązań, znak równości dla gniazd, minus dla urządzeń niestniejących, znak plus dla urządzeń istniejących, pionową kreskę (|) dla kolejek FIFO, tyldę dla dowiązań symbolicznych, i wykrzyknik dla dowiązań wskazujących na nieistniejący plik.

mark    Gwiazdka jeśli plik jest zaznaczony, spacja jeśli nie jest.

mtime   czas ostatniej modyfikacji pliku.

atime   czas ostatniego dostępu do pliku.

ctime   czas utworzenia pliku.

perm    tekst reprezentujący aktualne uprawnienia do pliku.

mode    wartość (cyfrowa) przedstawiająca prawa do pliku.

nlink   liczba dowiązań do pliku. ngid GID (numeryczny).

nuid    UID (numeryczny).

owner   właściciel pliku.

group   grupa pliku.

inode   numer i-węzła pliku.

Możesz również używać następujących znaków dla zmiany wyświetlania:

space   spacja w formacie wyświetlania.

|       Ten znak jest używany w celu dodania pionowej linii od formatu wyświetlania.

Żeby wymusić szerokość pola, po prostu dodaj ':' a potem ilość znaków jakie chcesz żeby miało pole. Jeśli numer zaczyna się od '+', to szerokość nie może być mniejsza od podanej, jeśli program zobaczy, że jest jeszcze trochę miejsca na ekranie, rozszerzy to pole.

Na przykład tryb Full wyświetla w formacie:

half type name | size | mtime

A format Long wyświetla w formacie:

full perm space nlink space owner space group space size space mtime space name

A to jest całkiem ładny tryb użytkownika:

half name | size:7 | type mode:3

Panele mogą być również przestawione do następujących trybów:

Info    Tryb info wyświetla informację o aktualnie zaznaczonym pliku i (jeśli to możliwe) o systemie plików.

Tree (drzewo)
        Widok drzewa jest całkiem podobny do widoku Drzewa katalogówDirectory Tree. Zobacz tę sekcję jeśli chcesz się dowiedzieć czegoś na ten temat.

Quick View
        W tym trybie, panele zostaną przełączone w tryb zredukowanego podglądu wyświetlającego zawartość aktualnego pliku. Jeśli zaznaczysz panel (klawiszem tab lub myszką), będziesz miał dostęp do większości komend podglądu.[Sort Order...]
Porządek sortowania (Sort order...)

Istnieje osiem porządków sortowania. Przez: nazwę, rozszerzenie, datę modyfikacje, datę odczytu, datę zmiany, rozmiar, numeru i-węzła i niesortowane. Porządek sortowanie możesz wybrać w oknie dialogowym porządku sortowania. Możliwe jest również wybranie porządku wstecznego (od tyłu).

Standardowo, katalogi są sortowane przed plikami, ale może to być zmienione przez opcję Mix all files (mieszaj wszystkie pliki).

[Filter...]
Filtry (Filter...)

Komenda filtra pozwala ci na podanie rozszerzenia, które musi być spełnione, żeby pliki były widoczne (na przykład *.tar.gz). Niezależnie od filtru katalalogi i dowiązania do katalogów są zawsze pokazywane.

[Reread]
Odśwież (Reread)

Komenda odśwież odświeża widok wszystkich plików w katalogów. Jest to użyteczne jeśli inny proces stworzył lub usunął jakiś pliki. Jeśli użyłeś panelu zewnętrznego, wszystkie informacje zostaną przywrócone do prawdziwego stanu.[File Menu]
Menu plików (File menu)


Midnight Commander używa klawiszy F1 - F10 jako skrótów klawiszowych do komend występujących w menu plików. Na terminalach bez funkcji klawiszowych (F1 - F10) można używać kombinacji klawisza Escape i numeru ( odpowiednio 1 dla F1, 2 dla F2 itd. )

Menu plików ma następujące komendy (skróty klawiszowe umieszczone są na dole ekranu):

Pomoc (F1)

Wywołuje wbudowaną przeglądarkę plików pomocy. Wewnątrz niej można używać klawisza Tab żeby przejść do następnego dowiązania, Enter żeby przejść do wybranego dowiązania. Klawisze Spacji i Backspace są używane do poruszania się naprzód i wstecz na stronach pomocy. Naciśnij klawisz F1 żeby uzyskać pełną listę dostępnych klawiszy w pomocy.

Menu (F2)

Wywołuje menu użytkownika. Menu użytkownika jest łatwym w użyciu narzędziem służącym do obsługi zewnętrznych programów i dodatkowych opcji Midnight Commandera.

Podgląd (F3, Shift-F3)

Włącza podgląd aktualnie wybranego pliku. Standardowowo wywoływany jest wbudowany podgląd plików, ale jeśli opcja "Use internal view" jest wyłączona, wywoływany jest zewnętrzny program do poglądu, wskazywany przez zmienną PAGER. Jeśli jednak zmienna PAGER nie została jeszcze zdefiniowana, wywoływana jest komenda "view". Jeśli użyjesz kombinacji klawiszy Shift-F3, pogląd zostanie wywołany bez jakiegokolwiek formatownia pliku.

Filtrowany podgląd (M-!)

Ta kombinacja klawiszy oczekuje na komendę i jej argument (argumentem standardowo jest wybrany aktualnie plik), całe wyjście programu przekierowywane jest do pliku, który zostaje automatycznie wyświetlony na ekranie w trybie podglądu.

Edycja (F4)

Aktualnie ta komenda wywołuje edytor vi(1) lub edytor wybrany w zmiennej środowiskowej, lub wbudowany wewnętrzny edytor plików jeśli opcja use_internal_edit jest włączona.

Kopiuj (F5)

Włącza okno dialogowe, w którym standardowo znajduje się ścieżka do katalogu w nieaktywnym panelu, po czym kopiuje aktualny plik (lub wybrane jeśli wybrano jakiekolwiek) do katalogu, który wybraliśmy w oknie dialogowym. Space for destination file may be preallocated relative to preallocate_space configure option. Podczas procesu kopiowania możesz go w każdej chwili przerwać wciskając C-c lub Esc. Żeby dowiedzieć się czegoś więcej na temat jokerów w ścieżce źródłowej (którymi najczęściej będą * lub ^\(.*\)$) i innych możliwych określeń w katalogu docelowym zobacz kategorię "Maski kopiowania/przenoszenia"

Na niektórych systemach możliwe jest kopiowanie w tle, robi się to klikając na przycisk backgorund (lub naciskając kombinację M-b w oknie dialogowym). Background Jobs jest używane do kontrolowania prac w tle.

Link (C-x l)

Tworzy sztywne dowiązanie do aktualnego pliku.

SymLink (C-x s)

Tworzy symboliczne dowiązanie do aktualnego pliku. Dla tych, którzy nie wiedzą co to jest dowiązanie: tworzenie dowiązania do pliku jest tak jak kopiowanie pliku, z tym tylko, że zarówno plik źródłowy i docelowy reprezentują ten sam plik. Na przykład, jeśli edytujesz jeden z tych plików, zmiany, które czynisz pojawiają się w obu plikach. Niektórzy mówią na dowiązania aliasy lub skróty.

Twarde dowiązanie wydaje się być prawdziwym plikiem. Po stworzeniu go nie ma możliwości rozróżnienia, który z plików jest oryginalny, a który jest dowiązaniem. Jest bardzo ciężko zauważyć, że wskazują one na ten sam plik. Używaj dowiązań twardych wtedy kiedy nie chcesz tego wiedzieć.

Dowiązanie symboliczne jest tylko odwołaniem do oryginalnego pliku. Jeśli ten plik zostanie wyrzucony, dowiązanie stanie się bezużyteczne. Jest całkiem łatwo zauważyć, że pliki odnoszą się w gruncie rzeczy do tego samego. Midnight Commander pokazuje znak "@" przed nazwą pliku jeśli jest dowiązaniem symbolicznym do innych (poza katalogami, przed którymi pokazuje tyldę (~)). Oryginalny plik wskazywany przez dowiązanie jest pokazywany w linii mini-statusu, jeśli opcja "Show mini-status" jest włączona. Używaj dowiązań symbolicznych, jeśli chcesz unikąć problemów z rozpoznawaniem twardych dowiązań.

Zmiana nazwy/przeniesienie (F6)

Włącza okno dialogowe, gdzie standardowo wpisana jest nazwa katalogu w nieaktywnym panelu, i przenosi aktualnie wybrany plik (lub zaznaczone jeśli choć jeden jest zaznaczony) do katalogu wpisanego w oknie dialogowym. Podczas procesu przenoszenia możesz użyć kombinacji klawiszy C-c lub ESC, żeby przerwać operację. Po więcej szczegółów zobacz operację Kopiuj opisaną powyżej. Większość rzeczy jest całkiem podobna.

Na niektórych systemach możliwe jest przenoszenie w tle, robi się to klikając na przycisk background (lub naciskając kombinację M-b w oknie dialogowym). Background Jobs jest używane do kontrolowania prac w tle.

"Utwórz katalog (F7)"

Włącza menu dialogowe i zakłada katalog o podanej nazwie

Kasuj (F8)

Kasuje aktualnie wybrany lub zaznaczone pliki w aktywnym panelu. Podczas procesu możesz nacisnąć C-C lub Esc żeby przerwać operację. [skasowane pliki nie będą jednak odzyskane - przyp. tłumacza].

Zaznacz grupę (+)

Używane do zaznaczania grupy plików. Midnight Commander będzie żądał tekstu opisującego grupę plików. Jeśli opcja Shell Patterns jest włączona, tekst będzie traktowany jako globalny dla interpretatora (* oznacza zero lub więcej znaków a ? oznacza jeden znak). Jeśli opcja Shell Patterns jest wyłączona, wtedy zaznaczanie plików jest robione z zastosowaniem norm zewnętrznych (zobacz ed (1)).

Odznacz grupę (\)

Używane do odznaczania grupy plików. Jest przeciwieństwem komendy Zaznacz pliki.

Wyjdź (F10, Shift-F10)

Zamyka Midnight Commandera. Shift-F10 jest używany jeśli używasz "wrappera" powłoki. Shift-F10 nie przeniesie cię do katalogu, w którym byłeś ostatnio w Midnight Commanderze, zamiast tego przejdzie do katalogu, z którego uruchomiłeś program.

[Quick cd]
Szybka zmiana katalogów (Quick cd) M-c

Ta komenda jest bardzo użyteczna, jeśli masz już pełną linię poleceń, a chcesz przejść do innego katalogu. Uruchamia ona małe okno dialogowe, w którym podajesz to co po normalnej komendzie cd po czym naciskasz Enter. Wszystkie opcje są dokładnie takie same jak we wbudowanej komendzie cd.

[Command Menu]
Menu komend (Command Menu)

Komenda drzewo katalogów (Directory tree) pokazuje drzewo katalogów.

Komenda "Find file" szuka pliku spełniającego podane warunki, natomiast komenda "Swap panels" zamienia zawartości obu paneli.

Komenda "Panels on/off" pokazuje wyjście ostatniej komendy interpetatora poleceń. Działa ona tylko na terminalach typu Linux lub FreeBSD.

Komenda porównywania katalogów (Compare directories) (C-x d) porównuje zawartości panelu katalogowego z drugim. Możesz potem użyc Kopiuj (F5) żeby stworzyć dwa dokładnie identyczne panele. Metoda "quick" porównuje tylko i wyłącznie rozmiary plików i ich daty. Metoda "thorough" porównuje pliki bajt po bajcie. Ta metoda działa tylko wtedy kiedy komputer obsługuje wywołanie mmap(2). Metoda "size-only" zwraca uwagę tylko na rozmiar plików. Nie ma dla niej żadnego znaczenia czy plik ma inną datę lub zawartość, liczy się tylko rozmiar.

Komenda historii komend (Command history) pokazuje listę wpisanych komend. Ta, którą wybierzesz, jest kopiowana do linii poleceń. Do historii komend można mieć dostęp również przy użyciu kombinacji M-p lub M-n.

Komenda hotlisty katalogów (Directory hotlist) (C-\) pozwala na zmienianie katalogów do tych najczęściej używanych dużo szybciej.

Komenda panelu zewnętrznego (External panelize) pozwala na wykonywania programów zewnętrznych i ustawienia zawartości paneli na to co zwróciła wywołana komenda.

Komenda edycji rozszerzeń plików (Edit Extension File) pozwala na własny wybór programów, które mają być używane do wykonywania plików z podanymi rozszerzeniami. Komenda edycji pliku menu (Edit Menu File) może być używana do edytowania menu użytkownika (tego, które pojawia się po naciśnięciu kombinacji F2).

[Directory Tree]
Drzewo katalogów (Directory Tree)

Możesz wybierać katalogi z drzewa katalogów i Midnight Commander przejdzie do wybranego przez Ciebie katalogu.

Są dwa sposoby wywoływania drzewa. Prawdziwa komenda drzewa katalogów jest dostępna z menu komend. Inną metodą jest wybranie drzewa z menu "lewego" bądź "prawego".

Żeby nie mieć zbyt dużych opóźnień Midnight Commander skanuje tylko małą ilość katalogów (tę potrzebną w danej chwili). Jeśli jakiegoś katalogu nie widać przejdź do jego katalogu nadrzędnego i naciśnij C-r (lub F2).

Możesz używać następujących klawiszy:

Generalne klawisze ruchu są akceptowane.

Enter. W drzewie katalogów, wychodzi z trybu drzewa i przechodzi znów do trybu zwykłego panelu. W podglądzie drzewa zmienia katalog w drugim panelu i zostaje w trybie podglądu drzewa w panelu aktywnym.

C-r, F2 (Rescan). Odświeża aktualny katalog. Używane jeśli drzewo nie jest już aktualne. Nie pokazuje katalogów, które już istnieją lub pokazuje te, których już nie ma.

F3 (Forget). Usuwa aktualny katalog z drzewa katalogów. Używaj tego jeśli chcesz usunąć "śmiecące" i niepotrzebne katalogi z wyświetlania. Żeby były one znów widoczne wystarczy nacisnąć F2.

F4 (Static/Dynamic). Przełącza pomiędzy dynamicznym (standardowo) i statycznym trybem nawigacji.

W trybie statycznym możesz używać strzałek do dołu i do góry do wybierania katalogu. Wszystkie zwiedzone katalogi są widoczne.

W trybie dynamicznym możesz używać strzałek w celu wybrania równorzędnego katalogu, strzałki w lewo żeby dostać się do katalogu domowego, strzałki w prawo w celu dostania się do katalogu podrzędnego. Widoczne jest tylko najbardziej aktualne drzewo katalogów. Drzewo zmienia się więc dynamicznie podczas twojego przemieszczania.

F5 (Copy). Kopiuje katalog.

F6 (RenMov). Przenosi katalog.

F7 (Mkdir). Tworzy nowy katalog poniżej aktualnego.

F8 (Delete). Kasuje katalog z systemu plików.

C-s, M-s. Szuka natępnego katalogu spełniającego podane warunki szukania. Jeśli taki nie istnieje te klawisze spowodują przemieszczenie się o jedną linię w dół.

C-h, Backspace. Kasuje ostatni znak w ciągu znaków do poszukiwania.

Jakikolwiek inny klawisz. Dodaje klawisz do ciągu znaków do szukania i przenosi do najbliższego katalogu, którego nazwa zaczyna się od tych znaków. W podglądzie drzewa musisz najpierw uaktywnić szukanie naciskając C-s. Ciąg szukający jest pokazywany w linii mini-statusu.

Następujące klawisze są dostępne tylko w drzewie katalogów. Nie działają one w poglądzie katalogów.

F1 (Help). Wywołuje podgląd pomocy i pokazuje tę sekcję.

Esc, F10. Wychodzi z drzewa. Nie zmienia katalogów.

Mysz jest obsługiwana. Podwójne kliknięcie ma znaczenie identyczne do klawisza Enter. Zobacz również sekcję Obsługa myszy.

[Find File]
Znajdź plik (Find File)

Komenda znajdź plik najpierw pyta się o startowy katalog do przeszukiwania i o nazwę pliku, który ma być znaleziony. Wciskając przycisk "Tree" (drzewo) możesz wybrać katalog startowy z drzewa katalogów.

Pole trzecie akceptuje wszystkie wyrażenia podobne do tych w egrep(1). Oznacza to, że musisz rozpoczynać znaki o specjalnym znaczeniu kombinacją "\" np. szukając "strcmp (" będziesz musiał wpisać "strcmp \(" (bez cudzysłowów oczywiście).

Możesz zacząć przeszukiwanie naciskając przycisk Ok. Podczas szukania możesz zatrzymać proces przy użyciu przycisku Stop i kontynuować po naciśnięciu Startu.

Możesz przeglądać liste znalezionych plików za pomocą strzałek do dołu i do góry. Komenda Chdir przejdzie do katalogu aktualnie wybranego. Przycisk Again zapyta się o nowe parametry do szukania (rozpocznie proces od nowa). Przycisk Quit kończy przeszukiwanie. Przycisk Panelize umieści znalezione pliki w aktywnym panelu katalogowym tak, że będziesz mógł wykonywać na nich standardowe czynności (podgląd, kopiowanie, przenoszenie, kasowanie itp.). Po spanelizowaniu wystarczy naciśnąć C-r żeby powrócić do normalnego trybu.

Możliwe jest posiadanie listy katalogów, których szukanie plików nie powinno uwzględniać (na przykład możesz chcieć ominąć przeszukiwanie CDROMu i innych podmontowanych systemów plików).

Katalogi do omijania powinny być umieszczone w zmiennej ignore_dirs w sekcji FindFile twojego pliku ~/.config/mc/ini.

Składowe katalogów powinny być oddzielone od siebie przez średniki, to jest przykład:

[FindFile]
ignore_dirs=/cdrom:/nfs/wuarchive:/afs

Możesz woleć używać panelu zewnętrznego do wykonywania niektórych operacji. Szukanie pliku jest dobre tylko dla prostych zapytań. Używając panelu zewnętrznego możesz dokonywać tak skomplikowanych wyszukiwań jak tylko pragniesz.

[External panelize]
Panel zewnętrzny

Panel zewnętrzny pozwala ci na wykonywanie zewnętrznych programów i oglądanie ich wyjścia jako zawartości aktywnego panelu.

Na przykład, jeśli chcesz aby w aktywnym panelu wyświetlone zostały wszystkie dowiązania w aktywnym katalogu, możesz użyć panelu zewnętrznego i następującej komendy:

find . -type l -print
Zanim komenda zakończy działanie, zawartość katalogów nie będzie już dłużej zawartością aktualnego katalogu, ale wszystkie pliki będą symbolicznymi dowiązaniami.

Jeśli chcesz wyświetlić wszystkie pliki, które ściągnąłeś ze swoich serwerów ftp, możesz użyć tej komendy awk żeby wypisać nazwę pliku z logów transferu:

awk '$9 ~! /incoming/ { print $9 }' < /var/log/xferlog

Możesz zapisać sobie często używane komendy pod jakąś nazwą, po to żeby móc ich potem używać dużo łatwiej. Robisz to po prostu wpisując komendę w linii wejściowej, a potem naciskająć przycisk Add. Potem wpisujesz nazwę, pod jaką ta komenda ma być widoczna. Następnym razem po prostu wybierasz tę komendę z listy i nie musisz już wpisywać jej ponownie.

[Hotlist]
Hotlist

Hotlista katalogów pokazuje nazwy katalogów wprowadzonych do hotlisty. Midnight Commander zmieni miejsce do tego, które wskazuje nazwa katalogu. Z hotlisty możesz wyrzucać już dodane pozycje par nazw/wskazań i dodawać nowe. Dla dodawania możesz wykorzystać kombinację (C-x h), która dodaje ścieżkę aktualnego katalogu do hotlisty. Użytkownik musi tylko podać pod jaką nazwą ma być ten katalog widoczny.

Powoduje to przechodzenie do częściej przeglądanych katalogów znacznie szybciej. Możesz używać ciągle wartości CDPATH opisanej w sekcji Wewnętrzne przemieszczanie.

[Edit Extension File]
Edycja rozszerzeń pliów (Edit Extension File)

Ta komenda wywoła twój edytor na plik ~/.config/mc/mc.ext.ini. If this file does not exist and you are not root, it will be copied from /opt/etc/mc/mc.ext.ini. If you are root, you can choose the file to edit: user's ~/.config/mc/mc.ext.ini or system-wide /opt/etc/mc/mc.ext.ini. The format of this file is described in detail in it. PP[Background Jobs]
Prace w tle (Background jobs)

Pozwalają ci one kontrolować status jakichkolwiek procesów wykonywanych w tle przez Midnight Commandera (tylko operacje kopiowania i przenoszenia, mogą być wykonywane w tle). Z tego menu możesz zastopować, zresetować i "zabić" proces w tle.

[Edit Menu File]
Edycja menu użytkownika (Edit Menu File)

Menu użytkownika jest bardzo użytecznym menu, które może być tworzone w sposób dowolny, przez użytkownika. Kiedy tylko próbujesz coś zrobić przy użyciu tego menu, ładowany jest plik .mc.menu z aktualnego katalogu, ale tylko wtedy kiedy jest on w posiadaniu użytkownika lub roota i mamy do niego prawa zapisu. Jeśli takiego nie ma próbuje się z plikiem ~/.config/mc/menu z tymi samymi założeniami, jeśli jego też nie ma - używa się standardowego pliku systemowego, który znajduje się w /opt/share/mc/mc.menu.

Format pliku z menu użytkownika jest bardzo prosty. Linie zaczynające się od czegokolwiek innego niż spacja lub tabulacja, są traktowane jako wtyczki do menu (aby móc używać ich potem jako gorących klawiszy, dobrze jest aby pierwszy znak był literą). Wszystkie linie zaczynające od spacji lub tabulacji, są komendami, które mają być wykonane jeśli wtyczka zostanie wybrana.

Kiedy opcja zostaje wybrana, wszystkie komendy należące do tej opcji kopiowane są do pliku w katalogu tymczasowym (najczęściej do /usr/tmp), a potem plik jest wykonywany. Pozwala to użytkownikowi wkładać normalne konstrukcje powłoki do konstrukcji kodu wykonywanego. Po więcej informacji zobacz, używania makr.

To jest przykładowy plik mc.menu:

A	Wyrzuć aktualny plik.
	od -c %f

B	Stwórz raport o błędzie i wyślij do roota.
	I=`mktemp ${MC_TMPDIR:-/tmp}/mail.XXXXXX` || exit 1
	vi $I
	mail -s "Błąd Midnight Commandera" root < $I
	rm -f $I

M	Przeczytaj pocztę.
	emacs -f rmail

N	Przeczytaj grupę dyskucyjną.
	emacs -f gnus

J	Skopiuj rekursywnie cały aktualny katalog.
	tar cf - . | (cd %D && tar xvpf -)

= f *.tar.gz | f *.tgz & t n
X       Zdekompresuj skompresowany plik tar.
	tar xzvf %f

Standardowe warunki

Każda opcja może być opatrzona w warunki. Warunek musi zaczynać się od pierwszej kolumny i od znaku '='. Jeśli warunek jest prawdziwy, opcja stanie się opcją domyślną.

Składnia warunku: 	= <warunek>
	    lub:	= <warunek> | <warunek> ...
	    lub:	= <warunek> & <warunek> ...

Warunek jest jednym z następujących:

  f <wzorzec>           aktualny plik zgodny z wzorcem?
  F <wzorzec>           plik w drugim panelu zgodny z wzorcem?
  d <wzorzec>           aktualny katalog spełniający wzorzec?
  D <wzorzec>           katalog w drugim panelu spełniający wzorzec?
  t <typ>               aktualny pliku typu typ?
  T <typ>               plik w drugim panelu typu typ?
  ! <warunek>           zaprzeczenie warunku

Wzorzec jest normalnym wzorcem powłoki lub wyrażeniem, podobnym do wzorca powłoki. Możesz zmienić globalne ustawienia wzorców powłoki pisząc "shell_patterns=x" w pierwszej linii menu użytkownika (x jest równe 0 lub 1).

Typ jest jednym lub więcej z podanych znaków:

  n	nie katalog
  r	zwykły plik
  d	katalog
  l	dowiązanie
  c	specjalny znak
  b	specjalny blok
  f	fifo
  s	gniazdo
  x	wykonywalny
  t	zaznaczony

Na przykład 'rlf' oznacza zwykły plik, dowiązanie lub fifo. Typ 't' jest trochę odmienny ponieważ dotyczy panelu a nie pliku. Warunek '=t t' jest prawdziwy jeśli są jakieś zaznaczone pliki w aktywnym panelu, a fałszywy jeśli nie ma.

Jeśli warunek rozpoczyna się od '=?' zamiast '=' droga przechodzenia przez warunki będzie pokazywana za każdym razem kiedy warunek będzie obliczany [przydatne do wyszukiwania błędów - przyp. tłumacza].

Warunki są obliczane od lewej do prawej. Oznacza to, że
	= f *.tar.gz | f *.tgz & t n
jest liczone tak samo jak
	( (f *.tar.gz) | (f *.tgz) ) & (t n)

To jest prosty przykład zastosowania tych warunków:

= f *.tar.gz | f *.tgz & t n
L	Listuje zawartość skompresowanego archiwum tar
	gzip -cd %f | tar xvf -

Warunki dodania

Jeśli warunek rozpoczyna się od znaku '+' (lub '+?') zamiast od '=' (lub '=?') jest to warunek dodania. Jeśli warunek jest prawdziwy, opcja menu będzie dołączona do menu. Jeśli nie jest prawdziwy, nie będzie ona w nim zawarty.

Możesz łączyć ze sobą standardowe i dodane warunki zaczynając warunek od kombinacji '+=' lub '=+' (lub '+=?' lub '=+?' jeśli chcesz zobaczyć trasę błędów). Jeśli chcesz użyć różnych warunków, dodanego i standardowego, możesz poprzedzić wpis menu dwoma wierszami warunkowymi. Jednym zaczynającym się od znaku '+', a drugim od '='.

Wszelkie komentarze rozpoczynają się od znaku '#'.

[Options Menu]
Menu opcji (Options Menu)

Midnight Commander ma niektóre opcje, które mogą być włączane lyb wyłączane w różnych oknach dialogowych z tego menu. Opcja jest włączona jeśli widnieje przed nią gwiazdka lyb "x".

Komenda Configuration włącza okno dialogowe, z którego możesz zmienić większość ustawień Midnight Commandera.

Menu Layout pozwala na zmianę wielu ustawień, które mają znaczący wpływ na to jak MC będzie wyglądał na ekranie.

Menu Confirmation włącza okno dialogowe, w którym możesz ustawić przy wykonaniu których operacji chcesz być pytany o potwierdzenie.

Menu Display bits pozwala określić jakiego typu znaki twój terminal jest w stanie wyświetlić.

Menu Learn Keys pokazuje okno dialogowe, w którym możesz poznać które klawisze nie działają i w razie problemów naprawić to.

Menu Virtual FS pokazuje okno, w którym możesz zmienić niektóre ustawienia dotyczące systemów VFS.

Komenda Save Setup zachowuje wszystkie ustawienia z menu Lewego, Prawego i Opcji.

[Configuration]
Konfiguracja

Opcje w tym oknie są podzielone na trzy grupy: opcje panelu (Panel Options), zatrzymaj po uruchomieniu (Pause after run) i inne opcje (Other Options).

Opcje panelu

Show Backup Files. Standardowo Midnight Commander nie wyświetla plików kończących się znakiem '~' (tak jak komenda ls -B w wersji GNU).

Show Hidden Files. Standardowo Midnight Commander wyświetla wszystkie pliki zaczynające się od kropki (tak jak ls -a).

Mark moves down. Standardowo kiedy zaznaczasz plik (zarówno przy klawisze Insert) linia wyboru przenosi się o jedno w dół.

Drop down menus. Kiedy ta opcja jest włączona, kiedy naciskasz klawisz F9 menu będzie aktywowane, w przeciwnym wypadku zostaniesz tylko przeniosiony do tytułów w tym menu i będziesz musiał wybrać opcję ręcznie przy użyciu strzałek bądź też przy użyciu pierwszej litery z nazwy konkretnego menu.

Mix all files. Jeśli ta opcja jest włączona, wszystkie pliki i katalogi są pomieszane razem. Jeśli zaś jest wyłączona, katalogi (i dowiązania do nich), są listowane na początku a pozostałe pliki dopiero za nimi.

Fast directory reload. Standardowo ta opcja jest wyłączona. Jeśli ją włączysz Midnight Commander będzie używał triku do sprawdzenia czy zawartość katalogu się zmieniła. Trik polega na tym, że sprawdza się i-węzeł katalogu i jeśli się on zmienił to katalog jest ładowany na nowo. Oznacza to przeładowywanie zawartości panelu tylko wtedy, kiedy tworzysz lub kasujesz pliki. Jeśli robisz inne zmiany (rozmiaru, właściciela, uprawnień, grupy itp.) będziesz musiał ręcznie przeładować widok (np. używając kombinacji klawiszy C-r).

Zatrzymaj po uruchomieniu

Po wykonaniu komendy, Midnight Commander może zrobić pauzę, po to abyś mógł spokojnie przejrzeć wyjście ostatniej komendy. Są trzy możliwe wartości dla tej zmiennej:

        Nigdy (Never) Oznacza, że nie chcesz widzieć wyjścia twojej komendy. Jeśli używasz termianala typu Linux lub FreeBSD czy też xterm, będziesz mógł jednak zobaczyć jej wyjście naciskając C-o.

        "On dumb terminals" Będziesz miał pauzę po uruchomieniu na terminalach, które nie są w stanie pokazywać widoku ostatniej komendy (na wszystkich terminalach, które nie są xtermami lub Linux).

        Zawsze (Always) Program zatrzyma się po wykonaniu każdej z twoich komend.

Inne opcje

Operacje weryfikacji (Verbose operation). Przełącza czy podczas kopiowania, kasowania, przenoszenia plików ma być pokazywane okno dialogowe pokazujące stopień zaawansowania. Jeśli masz powolny terminal, możesz chcieć wyłączyć weryfikację. Jest to wykonywane automatycznie za ciebie jeśli twój terminal jest wolniejszy niż 9600 bps.

Zliczaj wszystko (Compute totals). Jeśli ta opcja jest włączona, Midnight Commander zlicza wszytkie bajty plików, które są przeznaczone do kopiowania, przenoszenia, kasowania. Spowoduje to wyświetlanie dużo bardziej zaawansowanego wskaźnika postępu w zamian zmiejszając trochę prędkość. Ta opcja nie ma żadnego znaczenia jeśli opcja Verbose operation jest wyłączona.

Wzorce powłoki (Shell patterns). Standardowo komendy zaznacz (Select), odznacz (Unselect), i filtruj (Filter) będą używać wyrażeń takich samych jak powłoka. Oznacza to, że gwiazdka oznacza zero lub więcej znaków, znak zapytania dokładnie jeden znak, a każdy inny znak sam siebie. Jeśli ta opcja jest wyłączona, stosowane są te, których używa w komenda ed(1).

Auto Save Setup. Jeśli ta opcja jest włączona, kiedy wychodzisz z Midnight Commandera konfiguracja MC zostanie zachowana automatycznie (bez pytania) do pliku ~/.config/mc/ini.

Auto menus. Jeśli ta opcja jest włączona, menu użytkownika będzie włączone na starcie. Użyteczne do budowania menu dla nie unixowców.

Używaj wewnętrznego edytora (Use internal editor). Jeśli ta opcja jest włączona, do edycji plików używany jest wbudowany edytor plików. Jeśli ta opcja jest wyłączona, używany będzie edytor wybrany w zmiennej EDITOR. Jeśli żaden edytor nie został wybrany, używany będzie vi(1). Zobacz sekcję Wewnętrzny edytor plików.

Używaj wewnętrznego podglądu (Use internal viewer). Jeśli ta opcja jest włączona, wbudowany podgląd pliku jest używany do oglądania pliku. Jeśli ta opcja jest wyłączona, używany jest podgląd wybrany w zmiennej PAGER. Jeśli żaden podgląd nie został wybrany, wywoływana jest komenda view. Zobacz sekcję Wbudowany podgląd plików.

Dokańczanie: pokaż wszystkie (Complete: show all). Standardowo Midnight Commander pokazuje wszystkie możliwe dokończenia jeśli jest ich więcej, kiedy naciśniesz drugi raz klawisz M-Tab, za pierwszym razem, po prostu dokańcza to na ile można i wydaje krótki dźwięk. Jeśli chcesz widzieć wszystkie możliwości po pierwszym naciśnięciu M-Tab włącz tę opcję.

Obrotowy myślnik (Rotating dash). Jeśli ta opcja jest włączona, Midnight Commander będzie pokazywał obracający się myślnik w lewym górnym rogu, jeśli będzie akurat w trakcie wykonywania jakiegoś procesu.

Lynx-like motion. Jeśli ta opcja jest włączona, możesz używać strzałek przemieszczenia żeby automatycznie zmieniać katalog jeśli aktualnie wybrany katalog jest podkatalogiem, a linia poleceń jest pusta. Standardowo ta opcja jest wyłączona.

Dowiązania podążające cd (Cd follows links). Ta opcja, jeśli jest włączona, zmusza Midnight Commandera żeby podążał za łańcuchem katalogów przy zmienianiu go w panelu czy za pomocą komendy cd. To jest standardowe zachowanie basha. Jeśli jest wyłączona, Midnight Commander podąża za prawdziwą strukturą katalogów, więc cd .. jeśli wszedłeś do katalogu poprzez dowiązanie, przeniesie cię do prawdziwego katalogu na dysku, a nie tam gdzie wskazywało dowiązanie.

Bezpieczne kasowanie (Safe delete). Jeśli ta opcja jest włączona, nieumyślne kasowanie plików stanie się dużo trudniejsze. Standardowy wybór w linii potwierdzenia zmienia się z "Yes" na "No". Standardowo ta opcja jest wyłączona.

[Layout]
Wygląd (Layout)

Meny wygląd pozwala ci na różne warianty zmieniania ogólnego wyglądu zewnętrznego ekranu. Możesz wybrać, czy linia menu, linia poleceń, linia hintów (pomocy) i linia klawiszy funkcyjnych mają być widoczne. Na konsolach typu Linux lub FreeBSD możesz wybrać ile linii ma być pokazywanych na wyjściu okna.

Reszta powierzchni ekranu jest używana przez dwa panele katalogowe. Możesz wybrać nawet czy panele mają być ułożone poziomo czy pionowo. Kolejną możliwością jest zmiana ich standardowej szerokości (bądź wysokości). Jest ona standardowo równa, ale można to zmienić.

Standardowo cała zawartość panelu katalogowego jest wyświetlana tą samą barwą, ale możesz zmienić to tak aby uprawnienia i typy plików były wyświetlane specjalnym podświetlonym kolorem. Jeśli podświetlanie uprawnień jest włączone, część pól (ta z uprawnieniami i typami plików) będzie podświetlona przy użyciu koloru wybranego jako selected. Jeśli podświetlanie jest włączone, pliki są kolorowane w zależnośći od swojego typu (np. katalogi, pliki typu core, wykonywalne, ...).

Jeśli opcja Show Mini-Status jest włączona, jeden wiersz informacji statusowych na temat aktualnie wybranej rzeczy w panelu, będzie pokazany na dole panelu.

[Confirmation]
Potwierdzanie (Confirmation)

W tym menu możesz skonfigurować opcje potwierdzania dla kasowania, zastępowania, wykonywania przez naciśnięcie klawisza Enter, jak również wychodzenia z programu.

[Display bits]
Wyświetlanie znaków (Display bits)

Używane do konfigurowania zakresu znaków widocznych potem na ekranie. To ustawienie może być 7-bitowe jeśli twój terminal obsługuje tylko siedmiobitowe wyjście, ISO-8859-1 wyświetla wszystkie znaki z mapy ISO-8859-1 a pełny 8 bitowy przeznaczony jest dla tych terminali, które radzą sobie z wyświetlaniem znaków ośmiobitowych.

Zobacz sekcję Polskie znaki, po więcej szczegółów na temat ich używania w Midnight Commanderze.

[Learn keys]
Nauka klawiszy (Learn keys)

W tym oknie możesz przetestować czy twoje klawisz F1-F20, Home, End itp. pracują poprawnie na twoim terminalu. Często nie działają tak, ponieważ bazy danych terminali są poniszczone.

Przemieszczać się możesz za pomocą klawisza Tab, za pomocą klawiszy ruchu edytora vi ('h' lewo, 'j' dół, 'k' góra i 'l' prawo) i po tym jak już raz naciśniesz daną strzałkę (zaznaczy się ona na OK), za ich pomocą również.

Klawisze testujesz po prostu naciskając każdy z nich. Jak tylko naciśniesz klawisz i pracuje on zupełnie poprawnie, obok nazwy klawisza powinno pojawić się OK. Kiedy klawisz jest już sprawdzony, zaczyna pracować normalnie (np. F1 wciśnięty po raz pierwszy po prostu pokaże, że ten klawisz działa, ale naciśnięty po raz drugi pokaże pomoc). Taka sama sytuacja powtarza się przy strzałkach. Klawisz Tab powinien pracować zawsze.

Jeśli niektóre klawisze nie pracują poprawnie, nie zobaczysz OK obok ich nazwy po naciśnięciu ich. Możesz chcieć je naprawić. Robisz to najeżdżając na odpowiedni przycisk dla tego klawisza i naciskając Enter. Pokaże się wtedy czerwona wiadomość i zostaniesz poproszony o podanie odpowiedniego klawisza. Jeśli chcesz zrezygnować, po prostu naciśnij Esc i poczekaj do czasu kiedy wiadomość zniknie. W przeciwnym wypadku wciśnij klawisz, który sobie życzysz i również poczekaj na zniknięcie okna.

Kiedy skończysz już ze wszystkimi klawiszami, możesz nacisnąć Save żeby zachować zmiany do pliku ~/.config/mc/ini do sekcji [terminal:TERM] (gdzie TERM jest nazwą twojego aktualnego terminala) lub po prostu odrzucić je.

[Virtual FS]
Wirtualny system plików (Virtual FS)

Ta opcja daje ci kontrolę nad ustawieniami informacji wirtualnego systemu plików. Midnight Commander zachowuje w pamięci informacje związane z niektórymi wirtualnymi systemami plików, po to żeby kolejne połączenia przebiegały dużo szybciej (np. ściągane listy katalogów z serwerów ftp).

Niemniej jednak, żeby mieć dostęp do zawartości skompresowanego pliku (np. skompresowanego pliku tar) Midnight Commander musi stworzyć tymczasowy nieskompresowany plik na twoim dysku.

Dopiero kiedy informacje w pamięci i tymczasowe pliki na dysku są zgodne z zasobami, możesz chcieć zmienić parametry informacji znajdujących się w buforze podręcznym po to, żeby zmniejszyć obciążenie dysku do mninimum albo do zmaksymalizowania prędkości dostępu do najczęściej używanych systemów plików.

System plików tar jest całkiem inteligentny jeśli chodzi o przechowywanie plików: po prostu ściąga wejścia do katalogów i kiedy chcemy więcej szczegółów o nim to system je dla nas ściąga.

W rzeczywistości jednak, pliki tar najczęściej trzymane są jako skompresowane i jako iż natura tych plików nie pozwala na oglądanie ich bez dekompresji (nie ma tam widocznych od razu wejść do katalogów), system plików musi być najpierw zdekompresowany na dysk do pliku tymczasowego i dopiero potem MC ma do niego dostęp taki jak do normalnego pliku typu tar.

Teraz, kiedy tak kochamy odwiedzać różne pliki i zwiedzać systemy plików typu tar na całym dysku, jest całkiem prawdopodobne, że wyjdziesz z takiego pliku, a po krótkim czasie będziesz chciał wejdść do niego spowrotem. Ponieważ dekompresja jest powolna, Midnight Commander będzie robił kopie plików w pamięci na określony czas, po upływie którego pliki zostaną skasowane a miejsce zajmowane przez nie zwolnione. Standardowo ten czas ustawiony jest na jedną minutę.

System plików FTP trzyma listę katalogów z odwiedzanego przez nas serwera w buforze podręcznym. Jego ważność konfigurowana jest za pomocą opcji ftpfsdirectorycachetimeout. Mała wartość dla tej opcji może spowolnić wszystkie operacje na systemach ftp ponieważ każda operacja będzie wymagać kolejnych zapytań do serwera.

Ponadto możesz zdefiniować serwer proxy dla transferów ftp i skonfigurować Midnight Commandera tak, aby zawsze go używał. Zobacz sekcję System plików FTP (FTP File System) po więcej szczegółów.[Save Setup]
Zapisz ustawienia (Save Setup)

Na starcie Midnight Commander będzie próbował odczytać opcje startowe z pliku ~/.config/mc/ini. Jeśli on nie istnieje, odczyta on konfiguracje z ogólnodostępnego pliku /opt/share/mc/mc.ini. Jeśli on też nie istnieje MC użyje swoich domyślnych ustawień.

Komenda Save Setup tworzy plik ~/.config/mc/ini zachowując aktualne ustawienia lewego, prawego menu, jak również menu opcji.

Jeśli właczysz opcję auto save setup, MC zawsze będzie zachowywał standardowe ustawienie podczas wychodzenia.

Istnieją również ustawienia, które nie mogą być zmienione z poziomu menu. Dla tych ustawień musisz wyedytować swój plik konfiguracyjny za pomocą twojego ulubionego edytora. Zobacz sekcję Specjalne ustawienia po więcej informacji.



[Executing operating system commands]
Wykonywanie poleceń systemu operacyjnego (Executing operating system commands)

Możesz wykonywać komendy wpisując je bezpośrednio do linii poleceń Midnight Commandera, lub wybierając program, który chcesz wykonać za pomocą klawiszy przemieszczenia i nacisnąć Enter.

Jeśli naciśniesz Enter na pliku, który nie jest wykonywalny, Midnight Commander sprawdzi rozszerzenie pliku i porówna je z rozszerzeniami wybranymi w pliku rozszerzeń (Extensions File). Jeśli jakaś pozycja się zgadza, wykonywana jest komenda (raczej bardziej rozszerzone makro) powiązana z tym rozszerzeniem.

[The cd internal command]
Wbudowana komenda cd (The cd internal command)

Komenda cd jest interpretowana przez Midnight Commandera, nie dokładnie tak samo jak wykonuje to powłoka. Przez to rozkaz cd nie może zawierać wielu składników makr, które są standardowo dostępne, jednak niektórych potrafi używać:

Tylda Znak tyldy (~) jest zawsze równoznaczny z wpisaniem nazwy katalogu domowego. Jeśli po znaku tyldy dodasz jakiś login użytkownika, zostanie on zastąpiony przez katalog domowy wybranego użytkownika.

Na przykład, ~guest jest katalogiem domowym użytkownika guest, podczas kiedy ~/guest jest katalogiem guest w twoim katalogu domowym.

Poprzedni katalog (Previous directory) Możesz przeskakiwać do katalogu, w którym byłeś poprzednio, używając specjalnej nazwy katalogu '-' tak jak: cd -

katalogi CDPATH Jeśli katalog wybrany do przejścia nie jest w naszym aktualnym katalogu, to Midnight Commander używa ścieżki w zmiennej CDPATH do szukania w jakimkolwiek z wymienionych tam katalogów.

Na przykład, możesz ustawić swoją zmienną CDPATH na katalogi ~/src:/usr/src, pozwalając na zmianę katalogów na jakikolwiek inny wewnątrz ~/src i /usr/src, z miejsca w którym jesteś (np. cd linux przeniesie cię do katalogu /usr/src/linux).

[Macro Substitution]
Obsługa makr (Macro Substitution)


Kiedy używamy menu użytkownika, wykonujemy plik o znajomym rozszerzeniu, lub wykonujemy komendę z linii poleceń, możemy użyć kilku bardzo prostych makr.

Są to:

"%f"

        Nazwa aktualnego pliku.

"%d"

        Nazwa aktulnego katalogu.

"%F"

        Nazwa pliku w niewybranym panelu.

"%D"

        Nazwa katalogu w niewybranym panelu.

"%t"

        Aktualnie zaznaczone pliki.

"%T"

        Pliki zaznaczone w nieaktywnym panelu.

"%u" i "%U"

        Podobne w działaniu do %t i do %T jednak z tą różnicą, że pliki po ich użyciu zostaną odznaczone. Oznacza to, że można ich użyć tylko raz w jednym menu, ponieważ potem nie będzie już żadnych plików zaznaczonych.

"%s" i "%S"

        Wybiera: zaznaczone pliki jeśli są jakieś, w przeciwnym razie aktualny plik.

"%cd"

        To jest specjalne makro, które jest używane do zmieniania aktualnego katalogu na wybrany katalog, na którego froncie jesteśmy. Jest to używane przede wszystkim jako interfejs do wirtualnych systemów plików.

"%view"

        To makro jest używane żeby włączać wbudowany podgląd plików. Może być ono pojedynczo lub z grupą argumentów. Jeśli postanawiasz używać któregokolwiek z tych argumentów musisz je koniecznie wziąć w nawiasy.

        Argumentami są: ascii aby wymusić podgląd w trybie ascii; hex aby wymusić podgląd w trybie szesnastkowym; nroff przekazuje podglądowi, że powinien interpretować pogrubione i podkreślone sekwencje programu nroff; unformated aby przekazać podglądowi, żeby nie interpretował komend nroff aby zrobić tekst pogrubiony lub podkreślony.

"%%"

        Znak %

"%{jakiś tekst}"

        Pyta się o zmienną. Pokazuje się okienko wejściowe i tekst wewnątrz klamerek używany jest jako zachęta (prompt). Makro jest zastępowane tekstem wpisanym przez użytkownika. Użytkownik może nacisnąć ESC lub F10 aby anulować. To makro nie działa jeszcze w linii poleceń.

[The subshell support]
Obsługa podpowłoki (The subshell support)

Podpowłoka (powłoka w tle) jest opcją, która musi być wybrana przy kompilacji, działa ona z powłokami: bash, tcsh i zsh.

Jeśli powłoka w tle jest włączona do komplilacji, Midnight Commander będzie sobie tworzył kopie twojej powłoki (tej zdefiniowanej w zmiennej SHELL, a jeśli nie ma, to będzie czerpał bezpośrednio z pliku /etc/passwd) i odpalał pseudo terminal, zamiast wywoływać nową powłokę za każdym razem kiedy wywołujesz komendę, komenda będzie przekazana powłoce w tle, jak tylko ją napiszesz. To pozwala ci na zmianę wielu zmiennych, używanie funkcji powłoki i zdefiniowanych aliasów, które są ważne dopóki nie wyjdziesz z Midnight Commandera.

Jeśli używasz basha możesz wybrać startowe komendy twojej powłoki w tle w pliku ~/.local/share/mc/bashrc, a ustawienia klawiatury w ~/.local/share/mc/inputrc. Użytkownicy tcsh mogą wstawiać komendy startowe do pliku ~/.local/share/mc/tcshrc.

Jeśli kod powłoki w tle jest użyty, możesz zawiesić aplikację w dowolnej chwili po prostu naciskając kombinację C-o i przeskakując spowrotem do Midnight Commandera, jeśli zawiesisz jakąś aplikację nie będziesz mógł używać innych zewnętrznych komend zanim nie wyjdziesz z aplikacji, którą przerwałeś.

Extra dodatkiem do używania powłoki w tle jest to, że zachęta widoczna w Midnight Commanderze jest tą samą, którą aktualnie używasz w powłoce.

Zobacz sekcję Opcje po więcej informacji na temat tego, jak możesz kontrolować powłokę w tle.

[Chmod]
Chmod

Okno Chmod jest używane do zmieniania atrybutów grupy plików lub katalogów. Może być ono wywołane kombinacją C-x c.

Okno Chmod ma dwie części - Uprawnienia (Permissions) i Plik (File)

W sekcji Plik wyświetlana jest nazwa pliku lub katalogu i jego uprawnienia w formie liczbowej jak również właściciel i grupa.

W sekcji Uprawnienia jest kilka przycisków, z których każdy odpowiada za odpowiednie uprawnienie do pliku. Podczas zmieniania atrybutów, widzisz jak zmienia się wartość liczbowa w oknie Plik.

Do poruszania pomiędzy okienkami (przyciskami i polami do zaznaczania) używaj strzałek lub klawisza tab. Aby zmienić pola lub wcisnąć przycisk używaj klawisza spacji. Możesz również używać "gorących liter" aby go wybrać (są one podświetlonymi literami na przyciskach).

Aby uaktywnić wprowadzone zmiany wciśnij Enter.

Kiedy pracujesz z grupą plików, lub katalogów, możesz kliknąć na bit, który chcesz wybrać lub wyczyścić. Kiedy już wybrałeś bity, które chcesz zmienić, możesz wcisnąć jeden z przycisków aktywujących (Set marked lub Clear marked).

I w końcu, aby wprowadzić dokładnie takie zmiany jak wybrałeś, użyj przycisku [Set all], który zadziała na wszystkich wybranych plikach.

[Marked all] włącza tylko zaznaczone atrybuty do wybranych plików.

[Set marked] włącza zaznaczone bity w atrybutach wszystkich wybranych plików.

[Clean marked] czyści zaznaczone bity z atrybutów zaznaczonych plików.

[Set] ustawia atrybuty jednego pliku.

[Cancel] unieważnia komendę chmod.

[Chown]
Chown

Komenda chown jest używana do zmiany właściela/grupy pliku. Skrótem klawiszowym jest kombinacja C-x o.

[Advanced Chown]
Zaawansowane chown (Advanced Chown)

Zaawansowane chown jest komendą łączącą w sobie komendy chmod i chown. Możesz za jednym zamachem zmienić atrybuty i właściela/grupę pliku.

[File Operations]
Operacje na plikach (File Operations)

Kiedy kopiujesz, przenosisz lub kasujesz pliki, Midnight Commander pokazuje okno opisowe operacji na pliku. Pokazuje nazwę pliku, na którym aktualnie dokonuje się operacja. Widoczne są co najwyżej trzy linie postępu. Pierwsza (file) mówi nam jak duża część pliku została już przekopiowana. Druga (bytes) mówi jak duża część wszystkich zaznaczonych plików została przekopiowana jak do tej pory. Trzecia (count) mówi jaka ilość plików została już przekopiowana. Jeśli opcja verbose jest wyłączona, linia file i bytes nie jest pokazywana.

Są dwa przyciski na dole okna dialogowego. Naciskając przycisk Skip ominiemy resztę aktualnie "ruszanego" pliku. Naciskając przycisk Abort zatrzymamy całą operację, pominiemy resztę plików.

Są trzy inne okna dialogowe, które mogą się włączyć podczas operacji na plikach.

Okno błędów informuje nas o błędach zaistniałych podczas operacji na pliku. Są w nim trzy możliwości wyboru. Przycisk Skip mówi żeby pominąć wybrany plik, przycisk Abort żeby przerwać całą operacją, a Retry aby ponowić próbę (np. kiedy usunąłeś problem korzystając z innego terminala).

Okno zastępowania jest pokazywane kiedy próbujesz przenieść lub przekopiować plik, a taki już w miejscu docelowym istnieje. Okno pokazuje daty i wielkości obu plików. Naciśnij przycisk Yes aby nadpisać (zastąpić) stary plik nowym, No aby pominąć ten plik, alL aby zastąpić wszystkie pliki, nonE aby nigdy nie zastępować i Update aby zastąpić ale tylko wtedy kiedy plik źródłowy jest nowszy niż docelowy. Całą operację możesz przerwać naciskając przycisk Abort.

Okno rekursywnego kasowania jest pokazywane kiedy próbujesz skasować katalog, który nie jest pusty. Naciśnij przycisk Yes aby skasować katalog rekursywnie, No aby pominąć katalog, alL aby skasować wszystkie katalogi rekursywnie i nonE aby pominąć wszystkie katalogi, które nie są puste. Możesz przerwać całą opecją naciskając przycisk Abort. Jeśli wybrałeś przycisk Yes lub alL będziesz zapytany o potwierdzenie. Wybierz "yes" tylko jeśli jesteś pewien, że chcesz skasować wszystko rekursywnie.

Jeśli zaznaczyłeś pliki, i wykonujesz operacje tylko na nich, to jeśli operacja się udała zostaną one odznaczone, te, na których operacja nie przebiegła całkowicie pomyślnie, pozostaną zaznaczone.

[Mask Copy/Rename]
Maski kopiowania/przenoszenia (Mask Copy/Rename)

Operacje przenoszenia i kopiowania pozwalają ci na tłumaczenie nazw plików w łatwy sposób. Aby to zrobić, musisz wybrać odpowiednią maskę źródłową i najczęściej w nazwie docelowej użyć gwiazdek. Wszystkie pliki pasujące do maski źródłowej są kopiowane/przenoszone w zgodzie z maską docelową. Jeśli są jakieś pliki zaznaczone, tylko one są brane pod uwagę przy wybieraniu plików.

Są jeszcze inne opcje, które możesz ustawić:

Opcja Follow links mówi czy dowiązania i dowiązania twarde w katalogu źródłowym powinny być przenoszone jako dowiązania czy też powinna być przegrywana ich zawartość (plik, na który wskazują).

Opcja Dive into subdirs ... mówi co program ma robić, kiedy kopiuje się katalog, a taki już istnieje. Standardowo kopiuje się pliki do wewnątrz już istniejącego katalogu (dodaje), po włączeniu tej opcji kopiuje się katalog źródłowy do wnętrza tego katalogu. Może przykład pomoże:

Chcesz przekopiować zawartość katalogu foo do /bla/foo, które już istnieje. Normalnie (Dive nie jest włączone), mc skopiuje to dokładnie do /bla/foo. Po włączeniu tej opcji zawartość zostanie skopiowana do /bla/foo/foo ponieważ ten katalog już istnieje.

Opcja Preserve attributes mówi czy zachowywać oryginalne atrybuty pliku, czasy i jeśli jesteś rootem to nawet numery UID i GID. Jeśli ta opcja jest wyłączona używana jest aktualna wartość zmiennej umask.

"Use shell patterns on"

Jeśli opcja obsługi wzorców powłoki jest włączona, możesz używać znaków '*' i '?' w maskach źródłowych. Działają one tak jak w powłoce. W masce docelowej możesz używać tylko '*' i '\<cyfra>'. Pierwsza maska '*' w nazwie docelowej odnosi sie do pierwszej gwiazdki w masce źródłowej, druga do drugiej itd. Joker '\1' odnosi się do pierwszego jokera w masce źródłowej, '\2' odnosi się do drugiego i tak dalej aż do '\9'. Joker '\0' oznacza pełną nazwę pliku źródłowego.

Dwa przykłady:

Jeśli maska źródłowa jest "*.tar.gz", a miejscem docelowym jest "/bla/*.tgz" i plikiem, który ma zostać przekopiowany jest "foo.tar.gz", to kopią będzie "foo.tgz" w katalogu "/bla".

Załóżmy, że chcesz zaminieć miejscami nazwę i rozszerzenie pliku, tak, że plik "plik.c" ma być zmieniony na "c.plik" itp. Maska źródłowa powinna być następująca: "*.*", natomiast docelowa: "\2.\1".

"Use shell patterns off"

Kiedy wzorce powłoki są wyłączone, MC nie dokonuje automatycznego grupowania plików. Musisz użyć wyrażenia'\(...\)' w masce źródłowej aby zasygnalizować istnienie jokerów w masce docelowej. Jest to trochę łatwiejsze, ale też wymaga aby trochę się napisać. Z drugiej jednak strony, makra są bardzo podobne tych używanych kiedy wzorce powłoki są włączone.

Dwa przykłady:

Jeśli maską źródłową jest "^\(.*\)\.tar\.gz$", docelową jest "/bla/*.tgz" i plikiem do przekopiowania jest "foo.tar.gz", kopią będzie "/bla/foo.tgz".

Załóżmy, że chemy zamienić miejscami nazwę i rozszerzenia, tak, że plik "plik.c" będzie się nazywał "c.plik" itp. Maską źródłową powinno być "^\(.*\)\.\(.*\)$", a docelową "\2.\1".

"Konwersje nazwy (Case Conversions)"

Możesz również zmieniać nazwy plików. Jeśli użyjesz '\u' lub '\l' w masce docelowej, następny znak będzie przekonwertowany na duży lub mały, zależnie od podanej opcji.

Jeśli użyjesz '\U' lub '\L' w masce docelowej, następne znaki będą zmieniane na małe lub duże (zależnie od opcji), aż do napotkania znaku '\E' lub następnych '\U', '\L' bądź też końca linii.

Konwersje '\u' i '\l' mają wyższy priorytet niż '\U' i '\L'.

Na przykład, jeśli maską źródłową jest '*' (shell patterns on) lub '^\(.*\)$' (shell patterns off) i maską docelową jest '\L\u*', nazwa pliku będzie miała pierwszą literę dużą, ale pozostałe już małe, niezależnie od obecnej nazwy.

Możesz również używać '\' aby "podkreślić" znak. Na przykład, '\\' jest backsleshem, a '\*' jest gwiazdką.

[Internal File Viewer]
Wbudowany podgląd plików

Wbudowany podgląd plików pozwala na dwa tryby wyśmietlania: ASCII i hex. Aby przełączać się pomiędzy tymi trybami używaj klawisza F4. Jeśli masz zainstalowany program GNU gzip, będzie on automatycznie używany do dekompresji plików w przypadku wystąpienia takiej potrzeby.

Podgląd plików będzie próbował użyć najlepszej metody zalecanej przez system lub rozszerzenie pliku. Wbudowany podgląd plików będzie interpretował wiele ciągów znaków, i włączał podkreślenie lub pogrubienie, powodując tym samym dużo przyjemniejszy wygląd plików.

Kiedy jesteś w trybie hex, funkcja szukania akceptuje tekst w cudzysłowach równie dobrze jak wartości szesnastkowe.

Możesz mieszać ciągi znaków ze stałymi tak jak: "Ciąg" 0xFE 0xBB "więcej tekstu". Ciąg pomiędzy stałymi i cudzysłowami jest po prostu ignorowany.

Kilka wewnętrznych szczegółów na temat podglądu: Na systemach, które używają wywołania systemowego mmap(2), program mapuje pliki zamiast je ładować; jeśli system nie obsługuje mmap(2) lub plik pasuje do któregoś z wybranych filtrów, podgląd użyje jego rozszerzalnych buforów, dzięki temu ładując tylko te części, do których musisz mieć aktualnie dostęp (dotyczy również plików skompresowanych).

Tu jest lista akcji powiązanych z każdym klawiszem, który Midnight Commander obsługuje w wewnętrznym poglądzie.

F1 Wywołuje wbudowaną przeglądarkę pomocy.

F2 Przełącza tryb zawijania.

F4 Przełącza tryb wyświetlania.

F5 Idź do linii. Zostaniesz zapytany o numer linii i zostanie ona wyświetlona na ekranie twojego monitora.

F6, /. Szukaj wyrażeń w dalszej części.

?, Wsteczne wyszukiwanie wyrażenia.

F7 Normalne wyszukiwaniewyszukiwanie w trybie hex.

C-s. Zaczyna normalne szukanie jeśli nie było żadnego wcześniej, w przeciwnym razie szuka następnego wystąpienia.

C-r. Zaczyna szukanie wsteczne jeśli jeszcze żadnego nie było, w przeciwnym razie szuka następnego wystąpienia.

n. Szuka następnego wystąpienia.

F8 Przełącza tryby Raw i Parsed. Pokaże to plik w postaci takiej w jakiej został znaleziony na dysku, lub jeśli został wybrany jakiś filtr, bądź też plik spełnia wymagania w pliku mc.ext.ini, wyświetlane jest to co przekazuje filtr. Aktualne ustawienie jest zawsze przeciwne niż to napisane na przycisku, przycisk wskazuje zawsze to co się stanie po jego naciśnięciu.

F9 Przełącza pomiędzy trybami format i unformat. Kiedy tryb formatu jest włączony podgląd będzie interpretował niektóre sentencje i pokazywał tekst pogrubiony i podkreślony innymi kolorami. Wynika z tego, że przycisk wskazuje co innego niż jest aktualnie (patrz wyżej).

F10, Esc. Wychodzi z wbudowanego podglądu.

Page Down, space, C-v. Przewija jedną stronę naprzód.

Page Up, M-v, C-b, backspace. Przewija jedną stronę wstecz.

strzałka w dół. Przewija jedną linię naprzód.

strzałka w górę. Przewija jedną linię wstecz.

C-l. Odświeża ekran.

C-f. Przeskakuje do następnego pliku.

C-b. Przeskakuje do poprzedniego pliku.

M-r. Przełącza linijkę.

Możliwe jest poinstruowanie podglądu pliku jak ma wyświetlać plik, zobacz sekcję Edycja pliku rozszerzeń.[Internal File Editor]
Wbudowany edytor plików

Wbudowany edytor plików ma większość funkcji posiadanych przez inne edytory pełno-ekranowe. Jest wywoływany po naciśnięciu klawisza F4 o ile opcja use_internal_edit jest ustawiona w pliku startowyn. Ma maksymalny rozmiar pliku wynoszący szesnaście megabajtów i potrafi bez skazy edytować pliki binarne.

Opcje, które aktualnie posiada to: kopiowanie, przenoszenie, kasowanie, wycinanie i wklejanie bloków; klawisz dla klawisza undo; rozciągane menu; wklejanie plików; definiowanie makr; szukanie i zastępowanie wyrażeń regularnych; strzałki z Shiftem zaznaczające teksty w stylu MSW-MAC (tylko dla konsoli typu Linux); przełączanie trybu wstawiania-zastępowania; opcja pozwalająca na "przerzucenie" bloku tekstu przez komendę powłoki jak na przykład indent.

Edytor jest bardzo prosty w użyciu i nie wymaga żadnego przygotowania. Aby zobaczyć jakie są klawisze po prostu obejrzyj odpowiednie menu rozwijalne. Inne klawisze to: przemieszczanie z Shiftem zaznaczające tekst. Ctrl-Ins kopiuje do pliku mcedit.clip a Shift-Ins wkleja z pliku mcedit.clip. Shift-Del Wycina do mcedit.clip, a Ctrl-Del kasuje zaznaczony tekst. Klawisze dokończenia również dają Enter z automatycznym wcięciem. Podświetlanie myszą również działa, i możesz je przesłonić i spowodować normalne zaznaczanie tekstu (takie jak obsługuje terminal) po prostu trzymając klawisz Shift.

Aby zdefiniować makro, naciśnij Ctrl-R i potem naciśnij klawisze, które chcesz aby były wykonywane. Naciśnij ponownie Ctrl-R kiedy skończysz. Możesz również przyporządkować makro do dowolnego klawisza jaki chcesz naciskając ten klawisz. Makro jest wykonywane kiedy naciśniesz Ctrl-A i przyporządkowany klawisz. Makro jest wykonywane również jeśli naciśniesz klawisz Meta, Ctrl, lub Esc i wybrany klawisz, jednak tylko jeśli ten klawisz nie jest używane przez inne funkcje. Raz zdefiniowane, makro wędruje sobie do pliku ~/.local/share/mc/mcedit/mcedit.macros w twoim katalogu domowym. Możesz skasować makro kasując odpowiednią linię z tego pliku.

F19 sformatuje format C jeśli jest podświetlony. Żeby to działało, stwórz wykonywalny plik ~/.local/share/mc/mcedit/edit.indent.rc w twoim katalogu domowym zawierający poniższe:

#!/bin/sh
/usr/bin/indent -kr -pcs ~/.cache/mc/mcedit/mcedit.block>& /dev/null
cat /dev/null > ~/.cache/mc/mcedit/cooledit.error

Edytor wyświetla również znaki nieamerykańskie (160+). Kiedy edytujesz plik binarny, powinieneś ustawić opcję display bits do 7 bitów w menu opcji, aby utrzymać przejrzystość odstępów między znakami.

Zobacz sekcję Polskie znaki, aby poznać szczegóły na temat używania polskich znaków w Midnight Commanderze.

[Completion]
Dokańczanie


Pozwól Midnight Commanderowi pisać za ciebie.

Spróbuj użyć dokończenia na tekście przed aktualną pozycją. MC próbuje dokończyć tekst jako zmienną (jeśli tekst zaczyna się od znaku $), nazwę użytkownika (jeśli tekst zaczyna się od znaku ~), nazwę hosta (jeśli tekst zaczyna się od znaku @) lub komendę (jeśli jesteś w linii komend w pozycji gdzie możesz wpisać jakąś komendę, możliwe dokończenia będą zawierać również zarezerwowane słowa i wbudowane komendy powłoki). Jeśli żaden z powyższych warunków nie jest spełniony, próbuje się dokańczać nazwę pliku.

Nazwa pliku, nazwa użytkownika i hosta, pracuje we wszystkich liniach wejścia, dokańczanie komend pracuje tylko w wybranych. Jeśli dokańczanie jest rozbudowane (jest więcej różnych możliwości), MC wyda krótki dźwięk, a następna akcja będzie zależeć od wartości zmiennej Complete: show all w menu konfiguracja. Jeśli jest ona włączona, zostanie wyświetlona lista wszystkich możliwych nazw. Właściwą nazwę możesz wybrać za pomocą strzałek a potem naciskając klawisz Enter na właściwej pozycji. Możesz także nacisnąć pierwsze litery, którymi różnią się możliwości aby odrzucić tak dużą część dokończeń jak to tylko możliwe. Jeśli naciśniesz znowu M-Tab, pokazane zostaną tylko te pozycje, które zaczynają się od kolejnych podanych liter. Kiedy nie maja już więcej możliwości, okno znika, ale możesz je wcześniej schować używając klawiszy anulujących: Esc, F10 oraz strzałek w lewo i prawo. Jeśli Complete: show all jest wyłączone, okno z listą włącza się dopiero wtedy, kiedy naciskasz M-Tab po raz drugi. Za pierwszym razem MC wydaje tylko krótki dźwięk.

[Virtual File System]
Wirtualny system plików (Virtual File System)

Midnight Commander jest dostarczany z kodem pozwalający na dostęp do systemów plików. Ten kod nazywany jest wirtualnym systemem plików. Pozwala on Midnight Commanderowi manipulować plikami trzymanymi na systemach nie Unixowych.

Aktualnie Midnight Commander jest wyposażony w niektóre wirtualne systemy plików (VFS): lokalny system plików, używany do dostępu do typowych systemów plików Unixowych; ftpfs używanego do manipulowania plikami na zdalnych systemach na poprzez protokół FTP; tarfs używany do manipulania plikami w systemach tar i w skompresowanych systemach tar; undelfs, używany do odzyskiwania skasowanych plików na systemach typu ext2 (standardowy system pracy systemu Linux), fish (do manipulowania plikami poprzez połączenia powłok takich jak rsh czy ssh) i w końcu system mcfs (system plików Midnight Commandera), oparty o sieć.

Kod VFS potrafi interpretować poprawnie wszystkie nazwy ścieżek i przekazuje je do właściwego systemu plików. Format używany dla każdego z systemów plików jest opisany w swojej oddzielnej sekcji.

[FTP File System]
System plików FTP (FTP File System)

Ftpfs pozwala na manipulowanie plikami na zdalnych komputerach, do normalnego użytku, możesz próbować używać panelowych komend FTP i dowiązań (dostępnych z linii menu) lub zmienić ścieżkę bezpośrednio za pomocą zwykłej komendy cd wyglądającej tak jak poniżej:

ftp://[!][użytkownik[:hasło]@]komputer[:port][zdalny katalog]

Parametry użytkownik, port i zdalny katalog są opcjonalne. Jeśli wybierzesz element użytkownik Midnight Commander spróbuje zalogować się na zdalnym komputerze jako zadany użytkownik, w przeciwnym razie użyje twojego loginu. Opcjonalne jest również hasło, jeśli jest obecne zostanie użyte do nawiązania połączenia. To użycie nie jest zalecane (tak samo jak trzymanie tego w twojej hotliście, dopóki nie ustawisz odpowiednich uprawnień, aby nikt niepowołany nie miał do tego dostępu).

Przykłady:

    ftp://ftp.nuclecu.unam.mx/linux/local
    ftp://tsx-11.mit.edu/pub/linux/packages
    ftp://!behind.firewall.edu/pub
    ftp://guest@remote-host.com:40/pub
    ftp://miguel:xxx@server/pub

Aby połączyć się z serwerem znajdującym się za firewallem, będziesz musiał użyc przedrostka ftp://! aby wymusić na Midnight Commanderze używanie serwera proxy do transferu danch. Serwer proxy definiuje się w oknie dialogowym wirtualnego systemu plików.

Inną możliwością jest ustawienie opcji Always use ftp proxy w oknie konfiguracyjnym wirtualnego systemu plików. Skonfiguruje to program tak, aby zawsze używał serwera proxy. Jeśli ta zmienna jest ustawiona, program będzie robił dwie rzeczy: konsultował plik /opt/etc/mc/mc.no_proxy w celu znalezienia linii zawierających nazwy serwerów, które są lokalne (jeśli nazwa hosta zaczyna się od kropki, uznaje się, że jest to domena) i sprawdza czy jakieś hosty bez kropek w nazwie są widoczne bezpośrednio.

Jeśli używasz systemu ftpfs będąc za routerem filtrującym, który nie pozwala ci na używanie standardowej metody otwierania plików, możesz chcieć wymusić na programie używanie trybu passive-open. Aby tego używać ustaw opcję ftpfs_use_passive_connections w pliku inicjującym.

Midnight Commander przechowuje listę katalogów w buforze podręcznym. Czas wyrzucania bufora jest ustawiany w oknie dialogowym Wirtualnego Systemu Plików. To ma śmieszną właściwość taką, że nawet kiedy wystąpią jakieś zmiany w katalogu, nie będą one pokazane w strukturze katalogów, dopóki nie wymusisz tego przy użyciu kombinacji C-r. To jest dobre rozwiązanie (jeśli myślisz, że to jest bug, to pomyśl o pracy na zdalnych systemach położonych po drugiej stronie Atlantyku przy użyciu ftpfs :) ).

[Tar File System]
System plików tar (Tar File System)

System plików tar pozwala na dostęp w trybie tylko-do-odczytu do plików typu tar i do skompresowanych plików typu tar, za pomocą komendy chdir. Aby zmienić katalog na plik tar, możesz zmienić aktualny katalog używając następującej konstrukcji:

/nazwa_pliku.tar:utar/[katalogu-wewnątrza-archiwum]

Plik mc.ext.ini pozwala już na tworzenie skrótów do plików tar, oznacza to, że możesz wybrać jakiś plik tar i nacisnąć enter aby do niego wejść, zobacz sekcję Edycja pliku rozszerzeń po więcej szczegółów na temat tego jak zostało to pomyślane.

Przykłady

    mc-3.0.tar.gz/utar://mc-3.0/vfs
    /ftp/GCC/gcc-2.7.0.tar/utar://

Późniejszy podaje pełną ścieżkę archiwum tar.[FIle transfer over SHell filesystem]
Transfer plików pomiędzy systemami plików (FIle transfer over SHell filesystem)


System plików fish jest systemem opartym na sieci, który pozwala na manipulowanie plikami na obcej maszynie tak jakby były one lokalne. Aby tego używać, druga strona musi również mieć ustawiony serwer fish, lub musi mieć powłokę kompatybilną z bashem.

Aby połączyć się z obcą maszyną, musisz tylko zmienić katalog do specjalnego katalogu, którego nazwa jest w następującym formacie:

sh://[użytkownik@]komputer[:opcje];/[zdalny-katalog];</em>
Elementy użytkownik, opcje i zdalny katalog są opcjonalne. Jeśli podasz użytkownika Midnight Commander spróuje zalogować się na obcy komputer jako zadany użytkownik w przeciwnym razie użyty zostanie twój login.

Jako opcja może wystąpić 'C' - włącza kompresje i 'rsh' - włącza rsh zamist ssh. Jeśli zdalny-katalog istnieje, twój aktualny katalog na zdalnym komputerze będzie ustawiony na niego.

Przykłady:

    sh://onlyrsh.mx:r/linux/local
    sh://joe@want.compression.edu:C/private
    sh://joe@noncompressed.ssh.edu/private
[Undelete File System]
Odzyskiwanie plików

Na systemach Linuksowych, jeśli dodałeś w konfiguracji opcję przywracania skasowanych plików z systemów ext2, będziesz w stanie to robić. Odzyskiwanie plików jest możliwe tylko i wyłącznie na systemach typu ext2. Przywracany system plików jest tylko nakładką na bibliotekę ext2fs: odzyskiwanie nazw wszystkich skasowanych plików i próba uczynienia z nich normalnej partycji.

Żeby używać tych systemów plików, będziesz musiał przejść od specjalnego pliku, którego nazwa składa się z przedrostka "undel://" i nazwy pliku, w której ów plik rezyduje.

Na przykład, aby odzyskać skasowane pliki z drugiej partycji pierwszego dysku scsi Linux, będziesz musiał użyć następującej ścieżki:

    undel:///dev/sda2

Może to chwilkę potrwać zanim pliki zostaną pokazane i będziesz mógł je normalnie oglądać.[EXTernal File System]
EXTernal File System

extfs allows to integrate numerous features and file types into GNU Midnight Commander in an easy way, by writing scripts.

Extfs filesystems can be divided into two categories:

1. Stand-alone filesystems, which are not associated with any existing file. They represent certain system-wide data as a directory tree. You can invoke them by typing 'cd fsname://' where fsname is an extfs short name (see below). Examples of such filesystems include audio (list audio tracks on the CD) or apt (list of all Debian packages in the system).

For example, to list CD-Audio tracks on your CD-ROM drive, type

  cd audio://

2. 'Archive' filesystems (like rpm, patchfs and more), which represent contents of a file as a directory tree. It can consist of 'real' files compressed in an archive (urar, rpm) or virtual files, like messages in a mailbox (mailfs) or parts of a patch (patchfs). To access such filesystems 'fsname://' should be appended to the archive name. Note that the archive itself can be on another vfs.

For example, to list contents of a zip archive documents.zip type

  cd documents.zip/uzip://

In many aspects, you could treat extfs like any other directory. For instance, you can add it to the hotlist or change to it from directory history. An important limitation is that you cannot invoke shell commands inside extfs, just like any other non-local VFS.

Common extfs scripts included with Midnight Commander are:

a       access 'A:' DOS/Windows diskette (cd a://).

apt     front end to Debian's APT package management system (cd apt://).

audio   audio CD ripping and playing (cd audio:// or cd device/audio://).

bpp     package of Bad Penguin GNU/Linux distribution (cd file.bpp/bpp://).

deb     package of Debian GNU/Linux distribution (cd file.deb/deb://).

dpkg    Debian GNU/Linux installed packages (cd deb://).

hp48    view and copy files to/from a HP48 calculator (cd hp48://).

lslR    browsing of lslR listings as found on many FTPs (cd filename/lslR://).

mailfs  mbox-style mailbox files support (cd mailbox/mailfs://).

patchfs extfs to handle unified and context diffs (cd filename/patchfs://).

rpm     RPM package (cd filename/rpm://).

rpms    RPM database management (cd rpms://).

ulha, urar, uzip, uzoo, uar, uha
        archivers (cd archive/xxxx:// where xxxx is one of: ulha, urar, uzip, uzoo, uar, uha).

You could bind file type/extension to specified extfs as described in the Edit Extension FileEdit Extension File section. Here is an example entry for Debian packages:

  regex/.deb$
          Open=%cd %p/deb://
[Polskie znaki]
Polskie znaki

Midnight Commander bardzo dobrze radzi sobie z obsługą znaków nieamerykańskich (160+) w tym polskich. Ważne jest aby mieć ustawione polskie znaki na konsoli (tzn. aby powłoka je obsługiwała). Jeśli używasz basha musisz tylko ustawić w pliku inputrc ( /etc/inputrc lub ~/.inputrc) następujące wartości:

set meta-flag on
set convert-meta off
set output-meta on

w pliku /etc/sysconfig/i18n:

SYSFONT=lat2u-16
SYSFONTACM=iso02

natomiast w pliku /etc/sysconfig keyboard:

KEYTABLE=pl

Potem użyj poleceń /sbin/setsysfont i loadkeys pl. [Zwróć uwagę na to, że te pliki są charakterystyczne dla dystrybucji RedHat, jeśli masz inną i wiesz jak to ustawić, to napisz do mnie, a ja to tu dopiszę [ patrz tłumacz na dole ;)) ]].

Teraz wystarczy już tylko włączyć odpowiednie opcje w menu opcji (klawisz F9). W menu opcji wybieramy Display bits i włączamy opcje ISO 8859-1 oraz Full 8 bits input. Potem zapisujemy konfigurację w opcje | Save setup.

I gotowe - polskie literki działają również w podglądzie i wbudowanym edytorze plików.

[Colors]
Kolory

Midnight Commander próbuje sprawdzić czy twój terminal obsługuje kolory używając bazy danych terminali. Czasami jest to zmieniane przez różne flagi startowe, np. możesz wymusić wyświetlanie czarno-białe lub kolorowe startując z opcją odpowiednio -b i -c.

Jeśli program jest skompilowany z menedżerem ekranu S-Lang zamiast ncurses, sprawdzi on również wartość zmiennej COLORTERM. Jeśli jest ustawiona, ma takie samo znaczenie jak opcja -c.

Możesz wybrać terminale, które zawsze żądają wyświetlania w kolorze, poprzez dodanie ich do pozycji color_terminals w sekcji pliku startującego. Uchroni to Midnight Commandera przed próbami odkrycia typu twojego terminala. Na przykład
[Colors]
color_terminals=linux,xterm
color_terminals=terminal-name1,terminal-name2...

Program może być skompilowany zarówno z bibliotekami S-Lang jak i ncurses. Ncurses nie obsługuje metody wymuszania wyświetlania, zawsze sprawdza w bazie danych terminali.

Midnight Commander umożliwia również zmianę standardowych barw ekranu. Aktualnie kolory są skonfigurowane przy użyciu zmiennej MC_COLOR_TABLE w sekcji Colors pliku startowego.

W sekcji kolorów, standardowa mapa kolorów jest ładowana ze zmiennej base_color. Możesz wybrać swoją własną mapę dla terminala poprzez użycie nazwy terminala jako klucza w tej sekcji. Na przykład:

[Colors]
base_color=
xterm=menu=magenta:marked=,magenta:markselect=,red

Format definicji kolorów jest następujący:

  <słowo kluczowe>=<kolor powierzchni">,<kolor tła>:<słowo kluczowe>= ...

Kolory są opcjonalne, a słowa kluczowe są następujące: normal, selected, marked, markselect, errors, input, reverse menunormal, menusel, menuhot, menuhotsel, menuinactive, gauge; kolory okien dialogowych: dnormal, dfocus, dhotnormal, dhotfocus; Kolory pomocy: helpnormal, helpitalic, helpbold, helplink, helpslink; Kolory podglądu: viewunderline; Specjalne tryby podświetlenia: executable, directory, link, device, special. Viewer colors are: viewnormal, viewbold, viewunderline, viewselected. Editor colors are: editnormal, editbold, editmarked, editwhitespace, editnonprintable, editlinestate. Popup menu colors are: pmenunormal, pmenusel, pmenutitle. [nie tłumaczyłem nazw z racji tego, że trzeba je stosować w ich angielskim brzmieniu - jeśli jesteś aż tak zaawansowany, użyj słownika].

Okna dialogowe mogą mieć następujące kolory: dnormal używany do normalnego tekstu, dfocus jest kolorem używanym do wyświetlania aktualnego komponentu, dhotnormal jest kolorem używanym do odróżnienia klawiszy w normalnych komponentach, a dhotfocus jest używany do wyświetlania owych w aktualnie wybranym.

Menu używa tego samego schematu, ale jako nazw kolorów używa menunormal, menusel, menuhot, menuhotsel i menuinactive.

Pomoc używa następujących kolorów: helpnormal używany do normalnego tekstu, helpitalic używa tej samej czcionki, którą wykorzystuje manual do wyświetlania czcionki typu italic, helpbold tak samo jak wyżej tylko czcionki są typu bold, helplink używane dla niewybranych jeszcze dowiązań i helpslink używane dla już wybranych.

gauge pokazuje kolor wypełnienia pokazywany przy wskaźniku postępu [ang. gauge], ukazującym ile procent pliku zostało przekopiowane itp. w graficzny sposób.

Dla trybu wysokiego podświetlania directory jest używane jako kolor do wyświetlania katalogów; executable dla plików wykonywalnych; link do wyświetlania dowiązań; device do wyświetlania plików urządzeń (devices); special dla plików specjalnych, takich jak gniazda FIFO i IPC; core dla wyświetlania plików typu core (zobacz również tę opcję w sekcji Specjalne ustawienia).

Możliwe kolory to: black, gray, red, brightred, green, brightgreen, brown, yellow, blue, brightblue, magenta, brightmagenta, cyan, brightcyan, lightgray and white. [sorry, że ich nazw nie tłumaczyłem, ale używać ich trzeba w oryginalnym brzmieniu :))].

[Special Settings]
Specjalne ustawienia

Większość ustawień Midnight Commandera może być zmieniana z poziomu menu. Pomimo tego jest pewna ilość ustawień, których zmiana możliwa jest jedynie poprzez zmianę w plikach konfiguracyjnych.

Opcje mogą być ustawione w twoim pliku ~/.config/mc/ini :

clear_before_exec.

        Standardowo Midnight Commander czyści ekran przed wykonaniem komendy. Jeśli chciałbyś widzieć wyjście komendy na dole ekranu, wyedytuj twój plik ~/mc/ini i zmień pole clear_before_exec na 0.

confirm_view_dir.

        Jeśli naciskasz F3 na katalogu, normalnie MC wchodzi do niego. Jeśli ta opcja ma wartość 1, MC zapyta się o potwierdzenie przed wejściem do tego katalogu, jeśli masz zaznaczone jakieś pliki.

drop_menus.

        Jeśli ta opcja jest ustawiona, kiedy naciskasz klawisz F9, rozciągane menu będzie od razu rozłożone, w przeciwnym wypadku znajdziesz się po prostu w najwyższym wierszu ekranu traktowanym jako menu. Będziesz musiał użyć strzałek lub pierwszych literek, aby wybrać konkretne menu.

ftpfs_retry_seconds.

        Wartość jest ilością sekund, przez które Midnight Commander będzie czekał cierpliwie zanim rozpocznie łączenie się z serwerem ftp od nowa. Dzieje się to wtedy kiedy serwer odmówił połączenia lub hasło jest nieprawidłowe. Jeśli wartość wynosi zero, nie nastąpi próba ponownego połączenia z serwerem.

ftpfs_use_passive_connections.

        Standardowo ta opcja jest wyłączona. Powoduje ona, że ftpfs otwiera połączenia pasywne dla transmisji danych. Jest to używane przez ludzi, którzy siedzą za ruterami filtrującymi. Działa to tylko wtedy, kiedy nie używasz serwera ftp proxy.

max_dirt_limit.

        Opisuje jak wiele odświeżeń ekranu może być maksymalnie ominięte we wbudowanym podglądzie plików. Normalnie ta wartość jest ważna, gdyż MC automatycznie dostosowuje liczbę odświeżeń do liczby naciśniętych klawiszy. Chociaż na bardzo wolnych komputerach lub na klawiaturach z szybkim powtarzaniem klawiszy, duża wartość mogłaby spowodować skoki ekranu i utratę płynności.

        Wydaje się, że wartość 10 dla max_dirt_limit jest najlepszym ustawieniem i to jest wartość standardowa tej funkcji.

mouse_move_pages.

        Kontroluje czy przewijanie w panelu za pomocą myszki odbywa się strona po stronie czy linijka po linjce.

mouse_move_pages_viewer.

        Tak samo jak wyżej tylko, że we wbudowanym wewnętrznym podglądzie plików.

navigate_with_arrows.

        Jeśli ta opcja jest włączona, możesz używać strzałek do automatycznego przemieszczanie się pomiędzy katalogami, jeśli linia poleceń jest pusta. (dotyczy to strzełek w bok).

nice_rotating_dash

        Jeśli jest włączony, Midnight Commander będzie pokazywał w lewym górnym rogu obracający się myślnik kiedy będzie wykonywał jakiś proces.

old_esc_mode

        Standardowo Midnight Commander traktuje klawisz ESC jako przedrostek (old_esc_mode=0). Jeśli włączysz tę opcję (old_esc_mode=1), to klawisz ESC będzie przedrostkiem dla innego klawisza, ale jeśli ten nie nastąpi, będzie on zinterpretowany jako klawisz anulowania (tak jak ESC ESC).


only_leading_plus_minus

        zmienia znaczenia znaków '+', '-', '*' w linii komend (wybór, odznaczenie, odwrócenie zaznaczenia). Standardowo działają one tylko wtedy kiedy linia poleceń jest pusta. Jeśli coś jest w niej już napisane, znaki te są traktowane jako normalne. Jest to przydatne gdyż najczęściej w trakcie pisania nie chcemy zmieniać zaznaczenia. Jednak czasami ... - wystarczy przestawić tę opcję i klawisze te będą zawsze działać. panel_scroll_pages

        Jeśli ustawione (standardowo), panel będzie przewijany o połowę za każdym razem kiedy kursor dochodzi do dolnej lub górnej linii, w przeciwnym wypadku przewijanie będzie się odbywać linia po linii.

show_output_starts_shell

        Ta opcja pracuje jeśli nie używasz obsługi powłoki w tle. Kiedy użyjesz kombinacji klawiszy C-o i ta opcja jest włączona, będziesz miał nową powłokę. Jeśli nie, dowolny klawisz przywróci znów Midnight Commandera (C-o działa jak podgląd).

show_all_if_ambiguous.

        Standardowo Midnight Commander pokazuje wszystkie możliwe dokończenia jeśli jest ich więcej i naciśnięto kombinację M-Tab po raz drugi, za pierwszym razem dokończone zostanie tylko tyle ile jest to możliwe i jeśli będzie więcej możliwości słychać będzie krótkie bipnięcie. Jeśli chcesz widzieć wszystkie możliwe dokończenia już po pierwszym naciśnięciu M-Tab, zmień tę opcję na 1.

torben_fj_mode

        Jeśli ta opcja jest włączona, klawisze home i end będą działały troszkę inaczej w panelach, zamiast przemieszczać linię wyboru do pierwszej lub ostatniej linii w panelu, będą działały tak jak jest to opisane poniżej:

        Klawisz home będzie: przechodził do środkowej linii, jeśli jest pod nią; w przeciwnym wypadku będzie przechodził do najwyższej linii w panelu, jeśli już w niej jest, będzie przechodził do pierwszego pliku w panelu.

        Klawisz end ma podobne zastosowanie: przechodzi do środkowej linii, jeśli jest nad nią; w przeciwnym wypadku przechodzi do najniższej linii w panelu, chyba że już się w niej znajduje, wtedy przechodzi do ostatniego pliku w panelu.

highlight_mode Standardowo wszystkie informacje w panelach są wyświetlane tym samym kolorem. Jeśli ta warość jest ustawiona na 1, to uprawnienia lub tryb będą wyświetlane przy użyciu podświetlonej barwy, tak aby pokazać ustawienia dla użytkownika. Tak więc prawa do odczytu, zapisu i wykonywania będą wyświetlane na żółto (tzn. kolorem selected). W dodatku jeśli ta zmienna jest ustawiona na 2, to całe linie są wyświetlane w kolorze odpowiadającym ich typowi (zobacz sekcję Kolory). Podświetlenie uprawnień również pracuje w tym trybie.

use_file_to_guess_type

        Jeśli ta zmienna jest ustawiona (standardowo) próbuje się dostosować rozszerzenie pliku do tego wybranego w pliku mc.ext.ini.

xtree_mode

        Jeśli ta opcja jest włączona (standardowo tak nie jest) kiedy przeglądasz plik w panelu drzewa, będzie on automatycznie przeładowywał drugi panel na zawartość wybranego katalogu.

[Terminal databases]
Baza danych terminali (Terminal databases)

Midnight Commander pozwala ci na naprawienie bazy danych terminali bez posiadania uprawnień roota. Midnight Commander szuka w pliku startowym (mc.lib położonego w katalogach z bibliotekami Midnight Commandera) lub w pliku ~/.config/mc/ini sekcji "terminal:nazwa-twojego-terminala" i potem sekcji "terminal:general", każda linia sekcji zawiera symbol klawisza, który chcesz zdefiniować, zaczynające się do znaku równości i definicji klawisza. Możesz użyć kombinacji \E aby reprezentować znak escape i ^x aby reprezentować znak Control-x.

Możliwymi klawiszami symboli są:

f0 do f20     Klawisze funkcyjne f0-f20
bs            backspace
home          klawisz home
end           klawisz end
up            strzałka w górę
down          strzałka w dół
left          strzałka w lewo
right         strzałka w prawo
pgdn          klawisz page down
pgup          klawisz page up
insert        znak insert
delete        znak delete
complete      do dokańczania

Na przykład, aby zdefiniować klawisz insert jako Escape + [ + O + p, możesz ustawić to pliku ini:

insert=\E[Op

Symbol klawisza complete reprezentuje sekwencję wyjścia używaną do wywoływania procesu dokańczania, jest to wywoływane kombinacją M-tab, ale możesz zdefiniować inne klawisze do wykonywania tych samych funkcji (na tych klawiaturach z toną fajnych i zupełnie bezużytecznych klawiszy).



[FILES]
PLIKI


Program będzie pobierał wszystkie swoje informacje ze zmiennej MC_DATADIR, jeśli jest ona nie ustawiona to znowu przetwarzany jest katalog /usr.

/opt/share/mc/help/mc.hlp

        Plik pomocy dla programu.

/opt/share/mc/mc.ext.ini

        Standardowy plik rozszerzeń plików.

~/.config/mc/mc.ext.ini

        Własny plik użytkownika, konfiguruje podgląd i edycje plików. Ma wyższy priorytet niż plik systemowy.

/opt/share/mc/mc.ini

        Standardowy plik setupu do Midnight Commandera, używany tylko wówczas, kiedy użytkownik nie ma swojego własnego pliku ~/.config/mc/ini.

/opt/share/mc/mc.lib

        Globalne ustawienia Midnight Commandera. Ustawienia w tym pliku są uwzględniane przez wszystkie sesje Midnight Commandera, użyteczne do definiowania ogólnosystemowych ustawień terminali.

~/.config/mc/ini

        Własny setup użytkownika. Jeśli ten plik jest dostępny, jest ładowany zamiast pliku globalnego.

/opt/share/mc/hints/mc.hint

        Plik zawierający podpowiedzi (hints) wyświetlane przez program.

/opt/share/mc/mc.menu

        Ten plik zawiera informacje o ogólnosystemowych aplikacjach w menu.

~/.config/mc/menu

        Własny plik menu użytkownika. Jeśli ten plik jest obecny jest używany zamiast pliku globalnego.

~~/.cache/mc/tree

        Lista katalogów drzewa katalogów i podglądu drzewa. Jedna linia jest jednym wejściem. Linie zaczynające się od ukośnika są pełnymi nazwami katalogów. Linie zaczynające się od numeru mają tyle znaków ile poprzedni katalog. Jeśli chcesz możesz stworzyć plik używając komendy "find / -type d -print | sort > ~/.cache/mc/tree". Normalnie nie ma sensu tego czynić, gdyż Midnight Commander robi to sam za ciebie.

./.mc.menu

        Lokalny plik zdefiniowany przez użytkownika. Jeśli ten plik jest dostępny, jest używany zamiast pliku w katalogu domowym i ogólnosystemowego.

To change default home directory of MC, you can use MC_PROFILE_ROOT environment variable. The value of MC_PROFILE_ROOT must be an absolute path. If MC_PROFILE_ROOT is unset or empty, HOME variable is used. If HOME is unset or empty, MC directories are get from GLib library.[AVAILABILITY]
DOSTĘPNOŚĆ

Najnowsza wersja programu jest do zdobycia na serwerze ftp.nuclecu.unam.mc w katalogu /linux/local i w Europie na serwerze sunsite.mff.cuni.cz w katalogu /GNU/mc i na serwerze ftp.teuto.de w katalogu /lmb/mc.[SEE ALSO]
ZOBACZ TAKŻE

ed(1), gpm(1), terminfo(1), view(1), sh(1), bash(1), tcsh(1), zsh(1).

Strona Midnight Commander w sieci World Wide Web:
	https://www.midnight-commander.org/

[AUTHORS]
AUTORZY

Miguel de Icaza (miguel@roxanne.nuclecu.unam.mx), Janne Kukonlehto (jtklehto@paju.oulu.fi), Radek Doulik (rodo@ucw.cz), Fred Leeflang (fredl@nebula.ow.org), Dugan Porter (dugan@b011.eunet.es), Jakub Jelinek (jj@sunsite.mff.cuni.cz), Ching Hui (mr854307@cs.nthu.edu.tw), Andrej Borsenkow (borsenkow.msk@sni.de), Norbert Warmuth (nwarmuth@privat.circular.de), Mauricio Plaza (mok@roxanne.nuclecu.unam.mx), Paul Sheer (psheer@icon.co.za) and Pavel Machek (pavel@ucw.cz) are the developers of this package; Alessandro Rubini (rubini@ipvvis.unipv.it) has been especially helpful debugging and enhancing the program's mouse support, John Davis (davis@space.mit.edu) also made his S-Lang library available to us under the GPL and answered my questions about it, and the following people have contributed code and many bug fixes (in alphabetical order):

Adam Tla/lka (atlka@sunrise.pg.gda.pl), alex@bcs.zp.ua (Alex I. Tkachenko), Antonio Palama, DOS port (palama@posso.dm.unipi.it), Erwin van Eijk (wabbit@corner.iaf.nl), Gerd Knorr (kraxel@cs.tu-berlin.de), Jean-Daniel Luiset (luiset@cih.hcuge.ch), Jon Stevens (root@dolphin.csudh.edu), Juan Francisco Grigera, Win32 port (j-grigera@usa.net), Juan Jose Ciarlante (jjciarla@raiz.uncu.edu.ar), Ilya Rybkin (rybkin@rouge.phys.lsu.edu), Marcelo Roccasalva (mfroccas@raiz.uncu.edu.ar), Massimo Fontanelli (MC8737@mclink.it), Pavel Roskin (pavel_roskin@geocities.com), Sergey Ya. Korshunoff (seyko2@gmail.com), Thomas Pundt (pundtt@math.uni-muenster.de), Timur Bakeyev (timur@goff.comtat.kazan.su), Tomasz Cholewo (tjchol01@mecca.spd.louisville.edu), Torben Fjerdingstad (torben.fjerdingstad@uni-c.dk), Vadim Sinolitis (vvs@nsrd.npi.msu.su) and Wim Osterholt (wim@djo.wtm.tudelft.nl).

[BUGS]
BŁĘDY

W pliku TODO dystrybucji znajdziesz informacje na temat tego, co pozostało jeszcze do zrobienia.

Jeśli chcesz zgłosić kłopoty z programem [błędy w nim], wyślij e-mail [po angielsku], na adres mc-devel@lists.midnight-commander.org.

Do zgłoszenia błędu dołącz opis problemu, versję programu, którego używasz (wyświetla ją mc -V), system operacyjny, na którym pracujesz i jeśli program się wykłada, chcielibyśmy dostać ślad stosu.[TŁUMACZENIE]
TŁUMACZENIE

Maciej Wojciechowski wojciech@staszic.waw.pl

[main]
 lqwqk     k           k     
 x x x .   x     .     x     
 x x x k lqu wqk k lqw tqk n 
 x x x x x x x x x x x x x x 
 v   v v mqv v v v mqu v v mj
     qqqqqqCommanderqj 

Główny ekran pomocy programu GNU Midnight Commander.

Aby dowiedzieć się, jak używać interaktywnej pomocy, należy nacisnąć klawisz EnterHow to use help. Można też przejść bezpośrednio do spisu treściContents.

Program GNU Midnight Commander został napisany przez jego autorówAUTHORS.

Program GNU Midnight Commander jest dostarczany BEZ JAKIEJKOLWIEK GWARANCJIWarranty. Niniejszy program jest wolnym oprogramowaniem; można go rozprowadzać dalej na warunkach GNU General Public LicenseLicense.

[License]

                 GNU GENERAL PUBLIC LICENSE
                   Version 3, 29 June 2007

Copyright © 2007 Free Software Foundation, Inc.
<http://fsf.org/>

    Everyone is  permitted  to copy  and  distribute  verbatim copies of this  license  document,  but  changing  it  is  not allowed.

                         Preamble

    The GNU General Public License is a free, copyleft license for software and other kinds of works.

    The licenses for most software and other practical works are designed to take away your freedom  to  share  and  change the works. By contrast, the  GNU  General  Public  License  is intended to guarantee your freedom to  share  and  change  all versions of a program to make sure it  remains  free  software for all its users. We, the Free Software Foundation,  use  the GNU General Public  License  for  most  of  our  software;  it applies also to any  other  work  released  this  way  by  its authors. You can apply it to your programs, too.

    When we speak of free software, we are referring  to freedom, not price. Our General Public Licenses  are  designed to make sure that you have the freedom to distribute copies of free software (and charge for them  if  you  wish),  that  you receive source code or can get it if you want it, that you can change the software or use pieces of it in new free  programs, and that you know you can do these things.

    To protect your rights, we need to prevent others from denying you these  rights  or  asking  you  to  surrender  the rights. Therefore, you have certain  responsibilities  if  you distribute copies of  the  software,  or  if  you  modify  it: responsibilities to respect the freedom of others.

    For example, if you distribute copies of such a program, whether gratis or for a fee, you must pass on to the recipients the same freedoms that you received. You must make sure that they, too, receive or can get the source  code. And you must show them these terms so they know their rights.

    Developers that use the GNU GPL protect your rights with two steps: (1) assert copyright on the software, and (2) offer you  this License giving you legal permission to copy, distribute and/or modify it.

    For the developers' and authors' protection, the GPL clearly explains that there is no warranty for this free software.  For both users' and authors' sake, the GPL requires that modified versions be marked as changed, so that their problems will not be attributed erroneously to authors of previous versions.

    Some devices are designed to deny users access to install or run modified versions of the software inside them, although the manufacturer can do so. This is fundamentally incompatible with the aim of protecting users' freedom to change the software. The systematic pattern of such abuseoccurs in the area of products for individuals to use, which is precisely where it is most unacceptable. Therefore, we have designed this version of the GPL to prohibit the practice for those products. If such problems arise substantially in other domains, we stand ready to extend this provision to those domains in future versions of the GPL, as needed to protect the freedom of users.

    Finally, every program is threatened constantly by software patents. States should not allow patents to restrict development and use of software on general-purpose computers, but in those that do, we wish to avoid the special danger that patents applied to a free program could make it effectively proprietary. To prevent this, the GPL assures that patents cannot be used to render the program non-free.

    The precise terms and conditions for copying, distribution and modification follow.

                   TERMS AND CONDITIONS

0. Definitions.
---------------

    “This License” refers to version 3 of the GNU General Public License.

    “Copyright” also means copyright-like laws that apply to other kinds of works, such as semiconductor masks.

    “The Program” refers to any copyrightable work licensed under this License. Each licensee is addressed as “you”. “Licensees” and “recipients” may be individuals or organizations.

    To “modify” a work means to copy from or adapt all or part of the work in a fashion requiring copyright permission, other than the making of an exact copy. The resulting work is called a “modified version” of the earlier work or a work “based on” the earlier work.

    A “covered work” means either the unmodified Program or a work based on the Program.

    To “propagate” a work means to do anything with  it  that, without permission, would make you directly or secondarily liable for infringement under applicable copyright law, except executing it on a computer or modifying a private copy. Propagation includes copying, distribution (with or without modification), making available to the public, and in some countries other activities as well.

    To “convey” a work means any kind of propagation that enables other parties to make or receive copies. Mere interaction with a user through a computer network, with no transfer of a copy, is not conveying.

    An interactive user interface displays “Appropriate Legal Notices” to the extent that it includes a convenient and prominently visible feature that (1) displays an appropriate copyright notice, and (2) tells the user that there is no warranty for the work (except to the extent that warranties are provided), that licensees may convey the work under this License, and how to view a copy of this License. If the interface presents a list of user commands or options, such as a menu, a prominent item in the list meets this criterion.


1. Source Code.
---------------

    The “source code” for a work means the preferred form of the work for making modifications to it. “Object code” means any non-source form of a work.

    A “Standard Interface” means an interface that either is an official standard defined by a recognized standards body, or, in the case of interfaces specified for a particular programming language, one that is widely used among developers working in that language.

    The  “System Libraries” of an executable work include anything, other than the work as a whole, that (a) is included in the normal form of packaging a Major Component, but which is not part of that Major Component, and (b) serves only to enable use of the work with that Major Component, or to implement a Standard Interface for which an implementation is available to the public in source code form. A “Major Component”, in this context, means a major essential component (kernel, window system, and so on) of the specific operating system (if any) on which the executable work runs, or a compiler used to produce the work, or an object code interpreter used to run it.

    The “Corresponding Source” for a work in object code form means all the source code needed to generate, install, and (for an executable work) run the object code and to modify the work, including scripts to control those activities. However, it does not include the work's System Libraries, or general-purpose tools or generally available free programs which are used unmodified in performing those activities but which are not part of the work. For example, Corresponding Source includes interface definition files associated with source files for the work, and the source code for shared libraries and dynamically linked subprograms that the work is specifically designed to require, such as by intimate data communication or control flow between those subprograms and other parts of the work.

    The Corresponding Source need not include anything that users can regenerate automatically from other parts of the Corresponding Source.

    The Corresponding Source for a work in source code form is
that same work.

2. Basic Permissions.
---------------------

    All rights granted under this License are granted for the term of copyright on the Program, and are irrevocable provided the stated conditions are met. This License explicitly affirms your unlimited permission to run the unmodified Program. The output from running a covered work is covered by this License only if the output, given its content, constitutes a covered work. This License acknowledges your rights of fair use or other equivalent, as provided by copyright law.

    You may make, run and propagate covered works that you do not convey, without conditions so long as your license otherwise remains in force. You may convey covered works to others for the sole purpose of having them make modifications exclusively for you, or provide you with facilities for running those works, provided that you comply with the terms of this License in conveying all material for which you do not control copyright. Those thus making or running the covered works for you must do so exclusively on your behalf, under your direction and control, on terms that prohibit them from making any copies of your copyrighted material outside their relationship with you.

    Conveying under any other circumstances is permitted solely under the conditions stated below. Sublicensing is not allowed; section 10 makes it unnecessary.

3. Protecting Users' Legal Rights From Anti-Circumvention Law.
--------------------------------------------------------------

    No covered work shall be deemed part of an effective technological measure under any applicable law fulfilling obligations under article 11 of the WIPO copyright treaty adopted on 20 December 1996, or similar laws prohibiting or restricting circumvention of such measures.

    When you convey a covered work, you waive any legal power to forbid circumvention of technological measures to the extent such circumvention is effected by exercising rights under this License with respect to the covered work, and you disclaim any intention to limit operation or modification of the work as a means of enforcing, against the work's users, your or third parties' legal rights to forbid circumvention of technological measures.

4. Conveying Verbatim Copies.
-----------------------------

    You may convey verbatim copies of the Program's source code as you receive it, in any medium, provided that you conspicuously and appropriately publish on each copy an appropriate copyright notice; keep intact all notices stating that this License and any non-permissive terms added in accord with section 7 apply to the code; keep intact all notices of the absence of any warranty; and give all recipients a copy of this License along with the Program.

    You may charge any price or no price for each copy that you convey,and you may offer support or warranty protection for a fee.

5. Conveying Modified Source Versions.
--------------------------------------

    You may convey a work based on the Program, or the modificationsto produce it from the Program, in the form of source code under the terms of section 4, provided that you also meet all of these conditions:

  a) The work must carry prominent notices stating that you modified it, and giving a relevant date.
  b) The work must carry prominent notices stating that it is released under this License and any conditions added under section 7. This requirement modifies the requirement in section 4 to “keep intact all notices”.
  c) You must license the entire work, as a whole, under this License to anyone who comes into possession of a copy. This License will therefore apply, along with any applicable section 7 additional terms, to the whole of the work, and all its parts, regardless of how they are packaged. This License gives no permission to license the work in any other way, but it does not invalidate such permission if you have separately received it.
  d) If the work has interactive user interfaces, each must display Appropriate Legal Notices; however, if the Program has interactive interfaces that do not display Appropriate Legal Notices, your work need not make them do so.

    A compilation of a covered work with other separate and independent works,
which are not by their nature extensions of the covered work, and which are not
combined with it such as to form a larger program, in or on a volume of a
storage or distribution medium, is called an “aggregate” if the compilation and
its resulting copyright are not used to limit the access or legal rights of the
compilation's users beyond what the individual works permit. Inclusion of a
covered work in an aggregate does not cause this License to applyto the other
parts of the aggregate.

6. Conveying Non-Source Forms.
------------------------------

    You may convey a covered work in object code form under the terms of sections 4 and 5, provided that you also convey the machine-readable Corresponding Source under the terms of this License, in one of these ways:

  a) Convey the object code in, or embodied in, a physical product (including a physical distribution medium), accompanied by the Corresponding Source fixed on a durable physical medium customarily used for software interchange.
  b) Convey the object code in, or embodied in, a physical product (including a physical distribution medium), accompanied by a written offer, valid for at least three years and valid for as long as you offer spare parts or customer support for that product model, to give anyone who possesses the object code either (1) a copy of the Corresponding Source for all the software in the product that is covered by this License, on a durable physical medium customarily used for software interchange, for a price no more than your reasonable cost of physically performing this conveying of source, or (2) access to copy the Corresponding Source from a network server at no charge.
  c) Convey individual copies of the  object code  with a copy of the written offer to provide the Corresponding Source. This alternative is allowed only occasionally and noncommercially, and only if you received the object code with such an offer, in accord with subsection 6b.
  d) Convey the object code by offering access from a designated place (gratis or for a charge), and offer equivalent access to the Corresponding Source in the same way through the same place at no further charge. You need not require recipients to copy the Corresponding Source along with the object code. If the place to copy the object code is a network server, the Corresponding Source may be on a different server (operated by you or a third party) that supports equivalent copying facilities, provided you maintain clear directions next to the object code saying where to find the Corresponding Source. Regardless of what server hosts the Corresponding Source, you remain obligated to ensure that it is available for as long as needed to satisfy these requirements.
  e) Convey the object code using peer-to-peer transmission, provided you inform other peers where the object code and Corresponding Source of the work are being offered to the general public at no charge under subsection 6d.

    A separable portion of the object code, whose source code is excluded from the Corresponding Source as a System Library, need not be included in conveying the object code work.

    A “User Product” is either (1) a “consumer product”, which means any tangible personal property which is normally used for personal, family, or household purposes, or (2) anything designed or sold for incorporation into a dwelling. In determining whether a product is a consumer product, doubtful cases shall be resolved in favor of coverage. For a particular product received by a particular user, “normally used” refers to a typical or common use of that class of product, regardless of the status of the particular user or of the way in which the particular user actually uses, or expects or is expected to use, the product. A product is a consumer product regardless of whether the product has substantial commercial, industrial or non-consumer uses, unless such uses represent the only significant mode of use of the product.

    “Installation Information” for a User Product means any methods, procedures, authorization keys, or other information required to install and execute modified versions of a covered work in that User Product from a modified version of its Corresponding Source. The information must suffice to ensure that the continued functioning of the modified object code is in no case prevented or interfered with solely because modification has been made.

    If you convey an object code work under this section in, or with, or specifically for use in, a User Product, and the conveying occurs as part of a transaction in which the right of possession and use of the User Product is transferred to the recipient in perpetuity or for a fixed term (regardless of how the transaction is characterized), the Corresponding Source conveyed under this section must be accompanied by the Installation Information. But this requirement does not apply if neither you nor any third party retains the ability to install modified object code on the User Product (for example, the work has been installed in ROM).

    The requirement to provide Installation Information does not include a requirement to continue to provide support service, warranty, or updates for a work that has been modified or installed by the recipient, or for the User Product in which it has been modified or installed. Access to a network may be denied when the modification itself materially and adversely affects the operation of the network or violates the rules and protocols for communication across the network.

    Corresponding Source conveyed, and Installation Information provided, in accord with this section must be in a format that is publicly documented (and with an implementation available to the public in source code form), and must require no special password or key for unpacking, reading or copying.

7. Additional Terms.
--------------------

    “Additional permissions” are terms that supplement the terms of this License by making exceptions from one or more of its conditions. Additional permissions that are applicable to the entire Program shall be treated as though they were included in this License, to the extent that they are valid under applicable law. If additional permissions apply only to part of the Program, that part may be used separately under those permissions, but the entire Program remains governed by this License without regard to the additional permissions.

    When you convey a copy of a covered work, you may at your option remove any additional permissions from that copy, or from any part of it. (Additional permissions may be written to require their own removal in certain cases when you modify the work.) You may place additional permissions on material, added by you to a covered work, for which you have or can give appropriate copyright permission.

    Notwithstanding any other provision of this License, for material you add to a covered work, you may (if authorized by the copyright holders of that material) supplement the terms of this License with terms:

  a) Disclaiming warranty or limiting liability differently from the terms of sections 15 and 16 of this License; or
  b) Requiring preservation of specified reasonable legal notices or author attributions in that material or in the Appropriate Legal Notices displayed by works containing it; or
  c) Prohibiting  misrepresentation of the origin of that  material, or requiring that modified versions of such material be marked in reasonable ways as different from the original version; or
  d) Limiting the use for publicity purposes of names of licensors or authors of the material; or
  e) Declining to grant rights under trademark law for use of some trade names, trademarks, or service marks; or
  f) Requiring indemnification of licensors and authors of that material by anyone who conveys the material (or modified versions of it) with contractual assumptions of liability to the recipient, for any liability that these contractual assumptions directly impose on those licensors and authors.

    All other non-permissive additional terms are considered “further restrictions” within the meaning of section 10. If the Program as you received it, or any part of it, contains a notice stating that it is governed by this License along with a term that is a further restriction, you may remove that term. If a license document contains a further restriction but permits relicensing or conveying under this License, you may add to a covered work material governed by the terms of that license document, provided that the further restriction does not survive such relicensing or conveying.

    If you add terms to a covered work in accord with this section, you must place, in the relevant source files, a statement of the additional terms that apply to those files, or a notice indicating where to find the applicable terms.

    Additional terms, permissive or non-permissive, may be stated in the form of a separately written license, or stated as exceptions; the above requirements apply either way.

8. Termination.
---------------

    You may not propagate or modify a covered work except as expressly provided under this License. Any attempt otherwise to propagate or modify it is void, and will automatically terminate your  rights  under  this  License  (including any patent licenses granted under the third paragraph of section 11).

    However, if you cease all violation of this License, then your license from a particular copyright holder is reinstated (a) provisionally, unless and until the copyright holder explicitly and finally terminates your license, and (b) permanently, if the copyright holder fails to notify you of the violation by some reasonable means prior to 60 days after the cessation.

    Moreover, your license from a particular copyright holder is reinstated permanently if the copyright holder notifies you of the violation by some reasonable means, this is the first time you have received notice of violation of this License (for any work) from that copyright holder, and you cure the violation prior to 30 days after your receipt of the notice.

    Termination of your rights under this section does not terminate the licenses of parties who have received copies or rights from you under this License. If your rights have been terminated and not permanently reinstated, you do not qualify to receive new licenses for the same material under section 10.

9. Acceptance Not Required for Having Copies.
---------------------------------------------

    You are not required to accept this License in order to receive or run a copy of the Program. Ancillary propagation of a covered work occurring solely as a consequence of using peer-to-peer transmission to receive a copy likewise does not require acceptance. However, nothing other than this License grants you permission to propagate or modify any covered work. These actions infringe copyright if you do not accept this License. Therefore, by modifying or propagating a covered work, you indicate your acceptance of this License to do so.

10. Automatic Licensing of Downstream Recipients.
-------------------------------------------------

    Each time you convey a covered work, the recipient automatically receives a license from the original licensors, to run, modify and propagate that work, subject to this License. You are not responsible for enforcing compliance by third parties with this License.

    An “entity transaction” is a transaction transferring control of an organization, or substantially all assets  of one, or subdividing an organization, or merging organizations. If propagation of a covered work results from an entity transaction, each party to that transaction who receives a copy of the work also receives whatever licenses to the work the party's  predecessor in interest had or could give under the previous paragraph, plus a right to possession of the Corresponding Source of the work from the predecessor in interest, if the predecessor has it or can get it with reasonable efforts.

    You may not impose any further restrictions on the exercise of the rights granted or affirmed under this License. For example, you may not impose a license fee, royalty, or other charge for exercise of rights granted under this License, and you may not initiate litigation (including a cross-claim or counterclaim in a lawsuit) alleging that any patent claim is infringed by making, using, selling, offering for sale, or importing the Program or any portion of it.

11. Patents.
------------

    A “contributor” is a copyright holder who authorizes use under this License of the Program or a work on which the Program is based. The work thus licensed is called the contributor's “contributor version”.

    A contributor's “essential patent claims” are all patent claims owned or controlled by the contributor, whether already acquired or hereafter acquired, that would be infringed by some manner, permitted by this License, of making, using, or selling its contributor version, but do not include claims that would be infringed only as a consequence of further modification of the contributor version. For purposes of this definition, “control” includes the right to grant patent sublicenses in a manner consistent with the requirements of this License.

    Each contributor grants you a non-exclusive, worldwide, royalty-free patent license under the contributor's essential patent claims, to make, use, sell, offer for sale, import and otherwise run, modify and propagate the contents of its contributor version.

    In the following three paragraphs, a “patent license” is any express agreement or commitment, however denominated, not to enforce a patent (such as an express permission to practice a patent or covenant not to sue for patent infringement). To “grant” such a patent license to a party means to make such an agreement or commitment not to enforce a patent against the party.

    If you convey a covered work, knowingly relying on a patent license, and the Corresponding Source of the work is not available for anyone to  copy, free of charge and under the terms of this License, through a publicly available network server or other readily accessible means, then you must either (1) cause the Corresponding Source to be so available, or (2) arrange to deprive yourself of the benefit of the patent license for this particular work, or (3) arrange, in a manner consistent with the requirements of this License, to extend the patent license to downstream recipients. “Knowingly relying” means you have actual knowledge that, but for the patent license, your conveying the covered work in a country, or your recipient's use of the covered work in a country, would infringe one or more identifiable patents in that country that you have reason to believe are valid.

    If, pursuant to or in connection with a single transaction or arrangement, you convey, or propagate by procuring conveyance of, a covered work, and grant a patent license to some of the parties receiving the covered work authorizing them to use, propagate, modify or convey a specific copy of the covered work, then the patent license you grant is automatically extended to all recipients of the covered work and works based on it.

    A patent license is “discriminatory” if it does not include within the scope of its coverage, prohibits the exercise of, or is conditioned on the non-exercise of one or more of the rights that are specifically granted under this License. You may not convey a covered work if you are a party to an arrangement with a third party that is in the business of distributing software, under which you make payment to the third party based on the extent of your activity of conveying the work, and under which the third party grants, to any of the parties who would receive the covered work from you, a discriminatory patent license (a) in connection with copies of the covered work conveyed by you (or copies made from those copies), or (b) primarily for and in connection with specific products or compilations that contain the covered work, unless you entered into that arrangement, or that patent license was granted, prior to 28 March 2007.

    Nothing in this License shall be construed as excluding or limiting any implied license or other defenses to infringement that may otherwise be available to you under applicable patent law.

12. No Surrender of Others' Freedom.
------------------------------------

    If conditions are imposed on you (whether by court order, agreement or otherwise) that contradict the conditions of this License, they do not excuse you from the conditions of this License. If you cannot convey a covered work so as to satisfy simultaneously your obligations under this License and any other pertinent obligations, then as a consequence you may not convey it at all. For example, if you agree to terms that obligate you to collect a royalty for further conveying from those to whom you convey the Program, the only way you could satisfy both those terms and this License would be to refrain entirely from conveying the Program.

13. Use with the GNU Affero General Public License.
---------------------------------------------------

    Notwithstanding any other provision of this License, you have permission to link or combine any covered work with a work licensed under version 3 of the GNU Affero General Public License into a single combined work, and to convey the resulting work. The terms of this License will continue to apply to the part which is the covered work, but the special requirements of the GNU Affero General Public License, section 13, concerning interaction through a network will apply to the combination as such.

14. Revised Versions of this License.
-------------------------------------

    The Free Software Foundation may publish revised and/or new versions of the GNU General Public License from time to time. Such new versions will be similar in spirit to the present version, but may differ in detail to address new problems or concerns.

    Each version is given a distinguishing version number. If the Program specifies that a certain numbered version of the GNU General Public License “or any later version” applies to it, you have the option of following the terms and conditions either of that numbered version or of any later version published by the Free Software Foundation. If the Program does not specify a version number of the GNU General Public  License, you may choose any version ever published by the Free Software Foundation.

    If the Program specifies that a proxy can decide which future versions of the GNU General Public License can be used, that proxy's public statement of acceptance of a version permanently authorizes you to choose that version for the Program.

    Later license versions may give you additional or different permissions. However, no additional obligations are imposed on any author or copyright holder as a result of your choosing to follow a later version.

[Warranty]
15. Disclaimer of Warranty.
---------------------------

    THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW. EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM “AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.

16. Limitation of Liability.
----------------------------

    IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND/OR CONVEYS THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS), EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

17. Interpretation of Sections 15 and 16.
-----------------------------------------

    If the disclaimer of warranty and limitation of liability provided above cannot be given local legal effect according to their terms, reviewing courts shall apply local law that most closely approximates an absolute waiver of all civil liability in connection with the Program, unless a warranty or assumption of liability accompanies a copy of the Program in return for a fee.

                      END OF TERMS AND CONDITIONS


               How to Apply These Terms to Your New Programs

    If you develop a new program, and you want it to be of the greatest possible use to the public, the best way to achieve this is to make it free software which everyone can redistribute and change under these terms.

    To do so, attach the following notices to the program. It is safest to attach them to the start of each source file to most effectively state the exclusion of warranty; and each file should have at least the “copyright” line and a pointer to where the full notice is found.

  <one line to give the program's name and a brief idea of what it does.>
  Copyright (C) <year>  <name of author>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.


Also add information on how to contact you by electronic and paper mail.


    If the program does terminal interaction, make it output a short notice like this when it starts in an interactive mode:

  <program>  Copyright (C) <year>  <name of author>
  This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
  This is free software, and you are welcome to redistribute it
  under certain conditions; type `show c' for details.


    The hypothetical commands `show w' and `show c' should show the appropriate parts of the General Public License. Of course, your program's commands might be different; for a GUI interface, you would use an “about box”.

    You should also get your employer (if you work as a programmer) or school, if any, to sign a “copyright disclaimer” for the program, if necessary. For more information on this, and how to apply and follow the GNU GPL, see <http://www.gnu.org/licenses/>.

    The GNU General Public License does not permit incorporating your program into proprietary programs. If your program is a subroutine library, you may consider it more useful to permit linking proprietary applications with the library. If this is what you want to do, use the GNU Lesser General Public License instead of this License. But first, please read <http://www.gnu.org/philosophy/why-not-lgpl.html>.

[QueryBox]
Okna zapytań

W oknach dialogowych zapytań można używać klawiszy strzałek lub pierwszych liter, aby wybrać element albo kliknąć na przycisku.

[How to use help]
Jak używać pomocy

Do obsługi przeglądarki można używać klawiszy kursora lub myszy. Naciśnięcie strzałki w dół przeniesie do następnego elementu lub przewinie w dół. Naciśnięcie strzałki w górę przeniesie do poprzedniego elementu lub przewinie w górę, Naciśnięcie strzałki w prawo podąży za zaznaczonym odnośnikiem. Naciśnięcie strzałki w lewo powróci do poprzednio odwiedzonego węzła.

Jeśli terminal nie obsługuje klawiszy kursora, można używać spacji do przewijania do przodu i klawisz B, aby przewijać do tyłu. Można używać klawisza Tab, aby przechodzić do następnego elementu i klawisza Enter, aby podążyć za zaznaczonym odnośnikiem. Klawisz L może być używany do przechodzenia do poprzednio odwiedzonego węzła. Naciśnięcie klawisza Esc zakończy przeglądarkę pomocy.

Lewy przycisk myszy podąży za odnośnikiem lub przewinie ekran. Prawy przycisk myszy może być używany, aby przechodzić do poprzednio odwiedzonego węzła.

Pełna lista klawiszy przeglądarki pomocy:

Ogólne klawisze ruchuGeneral Movement Keys są akceptowane.

Tab           Następny element.
M-Tab         Poprzedni element.
Dół           Następny element lub przewijanie o wiersz w dół.
Góra          Poprzedni element lub przewijanie o wiersz w górę.
Prawo, Enter  Podążanie za zaznaczonym odnośnikiem.
Lewo, l       Ostatnio odwiedzony węzeł.
F1            Pomoc dla przeglądarki pomocy.
N             Następny węzeł.
P             Poprzedni węzeł.
C             Przejście do Spisu treści.
F10, Esc      Zakończenie działanie przeglądarki pomocy.

Local variables:
fill-column: 58
end:
