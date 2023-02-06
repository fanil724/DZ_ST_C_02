#include <iostream>
#include "Human.hpp"
#include "Home.hpp"
#include "Apartment.hpp"
#include "Reservoir.hpp"
#include "ArrayReservoir.hpp"


int main() {
    //Задание 4
//    Human h("lrhtw", "lwgqhweo", 45, "erwighw", "geklhj");
//    //h.PrintHuman();
//    Human p = h;
//    p.SetName("popo");
//    //p.PrintHuman();
//
//    Apartament a;
//    a.Add(h);
//    a.Add(p);
//    Apartament b;
//    b.Add(h);
//    b.Add(p);
//
//
//    Home home;
//    home.Add(a);
//    home.Add(b);
//    home.PrintHome();

// Задание 5
    Reservoir res1("Kama",24,5,6);
    Reservoir res2("volga",5342,231,6746);
    Reservoir res3("Dnepr",453,45342,655432);
    ArrayReservoir arr;
    arr.Add(res1);
    arr.Add(res2);
    arr.Add(res3);
    arr.Print();
    std::cout<<res2.type_comparison(res3)<<std::endl;
    res2.area_comparison(res3).PrintReservoir();
    arr.Write();
}
