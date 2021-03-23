/// @file

/*! \brief Funkcja zapisu do pliku
 *
 * @param [in] tablica Tablica dwuwymiarowa przeznaczona do zapisu
 * @param [in] rozmiarX Szerokość zapisywanej tablicy
 * @param [in] rozmiarY Wysokość zapisywanej tablicy
 * @param [in] nazwa Nazwa zapisywanego pliku
 *
 */
void zapisPliku(int ** tablica, int rozmiarX, int rozmiarY, std::string nazwa);

/*! \brief Funkcja wczytywania tablicy z pliku
 *
 * @param [out] rozmiarX Do tej zmiennej będzie wprowadzona szerokość tablicy
 * @param [out] rozmiarY Do tej zmiennej będzie wprowadzona wysokość tablicy
 * @param [in] nazwa Nazwa wczytywanego pliku
 * @return Zwraca wczytaną tablicę dwuwymiarową
 */
int ** wczytajPlik(int * rozmiarX, int * rozmiarY, std::string nazwa);
