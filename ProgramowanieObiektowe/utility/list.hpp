///@file

#ifndef HEADER_GUARD_LIST
#define HEADER_GUARD_LIST
#include <cstdlib>
#include <stdexcept>


template <typename T>
/**
 * @brief The List Własna implementacja klasy List/Vector
 */
class List
{
    T *array;
    size_t size;
    size_t count;
public:
	/**
	 * @brief List konstruktor domniemany listy
	 */
	List()
	{
		array = new T[1];
		size = 1;
		count = 0;
	}
	/**
	 * @brief List Konstruktor listy z początkowymi elementami
	 * @param[in] elements lista inicjalizacyjna elementów typu listy
	 */
	List(std::initializer_list<T> elements): List(){
		for(auto e: elements){
			push(e);
		}
	}

	/**
	 * @brief push Dodawanie elementów do listy
	 * Metoda służąca dodawaniu elementów do istniejącej listy elementów typu T
	 * @param[in] element Dodawany element do listy
	 */
	void push(T element)
	{
		if (count == size)
		{
			T *temp = new T[2 * size];
			for (size_t i = 0; i < size; i++)
			{
				temp[i] = array[i];
			}
			delete[] array;
			size *= 2;
			array = temp;
		}
		array[count] = element;
		count++;
	}


	/**
	 * @brief getElement Getter elementu z listy
	 * Zwraca element zapisany w tablicy listy pod danym adresem.
	 * @param[in] index Indeks elementu w tablicy listy
	 * @throws std::out_of_range Wyrzucany gdy param index jest poza zakresem ilości elementów
	 * @return Element znajdujący się pod danym indeksem w tablicy
	 */
	T getElement(size_t index)
	{
		if (index < count)
		{

			return array[index];
		}
		else
		{
			throw std::out_of_range("Poza zakresem listy!");
		}
	}
	/**
	 * @brief operator [] Wrapper na getter elementów z tablicy
	 * Zwraca element zapisany w tablicy listy pod danym adresem.
	 *
	 * @param[in] index Indeks elementu w tablicy listy
	 *
	 * @throws std::out_of_range Wyrzucany gdy param index jest poza zakresem ilości elementów
	 *
	 * @return Element znajdujący się pod danym indeksem w tablicy
	 */
	T operator[](size_t index)
	{
		return getElement(index);
	}

	/**
	 * @brief pop Metoda "kasująca" ostatni element z listy
	 * Zmniejsza licznik elementów w liście
	 * @throws std::bad_array_new_length w przypadku próby redukcji licznika poniżej 0
	 */
	void pop(){
		if(count > 0)
		{
			count --;
		}
		else{
			throw std::bad_array_new_length();
		}
	}
	/**
	 * @brief getSize Getter na ilość elementów w liście
	 * @return Zwraca ilość elementów obecnie znajdujących się w liście
	 */
	int getSize(){
		return count;
	}
	/**
	 * @brief begin Początek tablicy
	 * @return Wskaźnik na początek tablicy elementów
	 */
	T* begin(){
		return array;
	}
	/**
	 * @brief end Koniec tablicy
	 * @return Wskaźnik na koniec tablicy elementów
	 */
	T* end(){
		return array+count;
	}
    
};

#endif
