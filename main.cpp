#include "range/v3/all.hpp"  // to je dovoljno za range-v3.
                             // Pojedini elementi se mogu "includati" i pojedinačno. 

using namespace ranges; // Nikako ne uključivati std!

struct Planet {
    std::string name;
    double gravity;
};


int main(){
        
    {
    // 1. Nađi planet s gravitacijom 11.15 m²/s. Rezultat vratiti (i ispisati)
    //    kao std::optional<std::string>.
    Planet const v[] = {{"Venus",8.87}, {"Mars",3.711}, {"Jupiter", 24.92},{"Neptun", 11.15},
                        {"Saturn", 10.44}, {"Uran",8.69}};
    // Vaš kod.
    }

    {
    // 2. Povežite stringove pomoću podvlake Koristite ranges::accumulate(). 
    const std::vector<std::string> v{"we", "will", "see"};
    // Vaš kod.
    }

    {
    // 3. Konvertiraj vektor cijelih brojeva (znamenaka) u broj (pomoću accumulate)
    auto const v = std::vector{1,7,5,6,9,3}; // retultat =  17569358
    // Vaš kod.
    }
    
    {
    // 4. Aproksimirajte broj  π koristeći Gregory - Leibnizovu formulu 
    // π ≈ 4 * ( 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...). Ispišite rezultat s 30 članova.
    // Vaš kod
    }

    {
    // 5. Selektirati domenu u web adresi i konverirati ju u string. Ispisati. 
    auto const str = std::string{"https://en.test.org"}; // -> org
    // Vaš kod
    }

    {
    // 6. Konvertirati binarni broj u decimalni. Testirati na sljedećem "broju":
    auto const v = std::vector<unsigned> {1,1,1,0}; //  1110_bin  = 14_dec
    // Vaš kod. 
    }

    {
    // 7. Izbaciti svaki treći element niza. Na primjer 0,1,2,3,4,5,6,7,8,... --> 0,1,4,5,6,7,9,... .
    auto seq = views::iota(0);
    // Vaš kod. 
    }
    
    return 0;
}
