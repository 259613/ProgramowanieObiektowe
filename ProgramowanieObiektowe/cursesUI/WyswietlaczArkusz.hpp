

namespace CursesMenu{
    class WyswietlaczArkusz{
        public:
        int rozmiarX, rozmiarY;
        int szerokoscElementu = 6;
        int ** tablica;

        public:
        WyswietlaczArkusz(int ** tablica, int x, int y);
        int wartoscElement(int x, int y);
        void zmienRozmiar(int ** tablica, int x, int y);
        void wyswietlArkusz(int x, int y);
        void obslugaArkusz();
        std::string stringLiczba(int x, int y);
    };
}