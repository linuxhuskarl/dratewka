#if !defined(MACRO)
#define MACRO

class pms_driver
{
private:
    /* data */

    int wazna_zmienna; //!< prywatna zmienna
    int wazna_zmienna2; //!< prywatna zmienna 2
    

public:
    /**
     * @brief PMS5003 Driver Constructor
     * Opis. Długi.
     * 
     * @param number Liczba, przydatna.
     */
    pms_driver(int * numer);
    ~pms_driver();

    /**
     * @brief Dodawanie dwóch liczb całkowitych.
     * 
     * opis.
     * 
     * @param a  pierwsza liczba
     * @param b druga liczba
     * 
     * @return suma dwóch liczb.
     */
    int dodaj(int a, int b);
};

#endif // MACRO
