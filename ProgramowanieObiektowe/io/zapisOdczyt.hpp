/// @file

/*! \brief Funkcja zapisu do pliku
 *
 * @param [in] tablica Tablica dwuwymiarowa przeznaczona do zapisu
 * @param [in] rozmiarX Szerokość zapisywanej tablicy
 * @param [in] rozmiarY Wysokość zapisywanej tablicy
 * @param [in] nazwa Nazwa zapisywanego pliku
 * @return Zwraca stan funkcji "0 - Funkcja wykonana", "1 - Niepoprawna nazwa pliku"
 *
 */
int zapisPliku(int ** tablica, int rozmiarX, int rozmiarY, std::string nazwa);

/*! \brief Funkcja wczytywania tablicy z pliku
 *
 * @param [in,out] tablica Tablica zostaje wykasowana i utworzona z nową wartością 
 * @param [out] rozmiarX Do tej zmiennej będzie wprowadzona szerokość tablicy
 * @param [out] rozmiarY Do tej zmiennej będzie wprowadzona wysokość tablicy
 * @param [in] nazwa Nazwa wczytywanego pliku
 * @return Zwraca stan funkcji "0 - Funkcja wykonana", "1 - Niepoprawna nazwa pliku", "2 - Niepoprawny format"
 */
int wczytajPlik(int*** tablica,int * rozmiarX, int * rozmiarY, std::string nazwa);
