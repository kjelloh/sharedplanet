//
//  ibi.cpp
//  ibi
//
//  Created by Kjell-Olov Högdahl on 2016-08-18.
//  Copyright © 2016 Kjell-Olov Högdahl. All rights reserved.
//

#include "ibi.hpp"
#include <string>
#include <iostream>

namespace ibi {

    void f() {}
    
    namespace test {

        void do_test() {
            {
                // Select test
                {
                    // auto composite = Composite<int,std::string>{{1,"Hallå"}, {2,"Världen"}};
                    // composite[0].add({{1,"Hur"},{2,"Står"}, {3,"det"}, {4, "till?"}});
                    // composite[1].add({{1,"Allt"},{2,"väl"}, {3,"med"}, {4, "dig?"}});

                    // auto selected = ibi::Select({1,2,2})(composite);
                    // if (selected) {
                    //      std::cout << "\nselected = " << *selected;
                    // }
                }
                // Path test
                {
                    Path<int> myIntPath;
                    Path<int> myIntPath2{1,2,3,4,5};
                    Path<int> myIntPath3 = {17,27,2,56};

                    std::cout << "\nmyIntPath2";
                    for (auto const &node : myIntPath2) {
                        std::cout << "\n\t" << node;
                    }

                    std::cout << "\nmyIntPath3";
                    for (auto const &node : myIntPath3) {
                        std::cout << "\n\t" << node;
                    }
                }
                Path<std::string> myStringPath;
                
                enum e_MyEnum {
                    eMyEnum_Undefined
                    ,e_MyEnum_Unknown
                };
                
                Path<e_MyEnum> myEnumPath;
                
            }
            // ZippedPath test
            {
                ZippedPaths<std::string, unsigned int> path({"Hej", "På", "Dig"},{1,2,3});
                for (auto i : path) {
                    // std::cout << "\n{" << i.get<1>() << "," << i.get<2>() << "}";
                    std::cout << "\n{" << i.get<0>() << "," << i.get<1>() << "}";
                }
            }
            {
                ZippedPaths<std::string, unsigned int> path = {{"Oj", 3},{"vad", 17},{"Fint",1}};
                for (auto i : path) {
                    // std::cout << "\n{" << i.get<1>() << "," << i.get<2>() << "}";
                    std::cout << "\n{" << i.get<0>() << "," << i.get<1>() << "}";
                }
            }
        }
    }    
}
