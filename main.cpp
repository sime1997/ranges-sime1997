#include "range/v3/all.hpp"  // to je dovoljno za range-v3.
                             // Pojedini elementi se mogu "includati" i pojedinačno. 
#include<iostream>
#include<vector>
using namespace ranges; // Nikako ne uključivati std!
#include "fmt/format.h"
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
    auto vv= v | ranges::views::filter([](auto x){ return x.gravity==11.15; });    
    std::cout<<"1. ";
    for(auto x : vv)
        {
            std::cout<<x.name<<std::endl;
        }
    
   }

    {
    // 2. Povežite stringove pomoću podvlake Koristite ranges::accumulate(). 
    const std::vector<std::string> v{"we", "will", "see"};
    // Vaš kod.
    auto s = accumulate(v | views::tail, front(v),[](auto const& a, auto const& b){return std::string{a + "_" + b};});
    std::cout<<"2: "<<s<<std::endl;
    }


    {
    // 3. Konvertiraj vektor cijelih brojeva (znamenaka) u broj (pomoću accumulate)
    auto const v = std::vector{1,7,5,6,9,3}; // retultat =  17569358
    // Vaš kod.
    auto help_function = [](std::string a, int b) {
                         return std::move(a) + std::to_string(b);
                     };
    std::string s = accumulate(std::next(v.begin()), v.end(),std::to_string(v[0]), help_function);
     
    std::cout<<"3: "<<s<<std::endl;
    }
    
    
    {
    // 4. Aproksimirajte broj  π koristeći Gregory - Leibnizovu formulu 
    // π ≈ 4 * ( 1 - 1/3 + 1/5 - 1/7 + 1/9 - ...). Ispišite rezultat s 30 članova.
    // Vaš kod

    int n=2;
    /*auto seq= views::iota(1,60) | views::stride(2);
    auto help=views::iota(0,2) | views::cycle;
    auto zipp = views::zip(seq,help); 
    auto r_repl = zipp | views::transform([n](auto const& p){return 
                                             (p.second == n-1) ?  -p.first : p.first;});

    auto v2 = r_repl | views::transform([](auto x){ return (double)1/x; });*/

    ///s manje varijabli
    auto v2 =  views::zip(views::iota(1,60) | views::stride(2),views::iota(0,2) | views::cycle) | 
               views::transform([n](auto const& p){return (p.second == n-1) ?  -p.first : p.first;}) | 
               views::transform([](auto x){ return (double)1/x; });


    double product = accumulate(v2.begin(), v2.end(), 0.0,std::plus<double>());
    
    std::cout<<"4. ";
    std::cout<<4*product<<std::endl;
    }


    {
    // 5. Selektirati domenu u web adresi i konverirati ju u string. Ispisati. 
    auto const str = std::string{"https://en.test.org"}; // -> org

     auto dash_fold = [](auto a,auto b) {
                         return a+b;};

    auto s=views::reverse(take_while_view ( views::reverse(str), [](auto x){ return x!='.'; }));
   
    std::string x= accumulate(s.begin(), s.end(),std::to_string(s[0]), dash_fold);
    std::cout<<"5. "<<x<<std::endl;
    } 

    {
    // 6. Konvertirati binarni broj u decimalni. Testirati na sljedećem "broju":
    auto const v = std::vector<unsigned> {1,1,1,0}; //  1110_bin  = 14_dec
    // Vaš kod. 
    auto reverse = v | views::reverse; 
    auto numbers = views::iota(0, distance(v)); 
    auto powers= numbers | views::transform([](int x){
                                return 1 << x;}); 
    auto s = inner_product(reverse,powers,0); 
    std::cout<<"6. "<<s<<std::endl;
    }


   {
    // 7. Izbaciti svaki treći element niza. Na primjer 0,1,2,3,4,5,6,7,8,... --> 0,1,4,5,6,7,9,... .
    // Vaš kod. 
    auto seq = views::iota(0,30);
    auto n=3;
    auto help=views::iota(0,n) | views::cycle;
    auto r_int_str = seq | views::transform([](int x) { return std::to_string(x);});//prebaci u string treba kasnije

    auto zipp = views::zip(r_int_str,help); 
    auto r_repl = zipp | views::transform([n](auto const& p){return 
                                             (p.second == n-1) ?  "_" : p.first;});

    
    auto first = r_repl | views::remove_if([](auto x){ return x=="_"; });
    std::cout<<"7. ";
    for(auto x:first)
        std::cout<<x<<" ";
    return 0;
   }
}
