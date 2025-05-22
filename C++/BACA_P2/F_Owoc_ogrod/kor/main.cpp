#include <iostream>
#include <ctime>
#include "garden.hpp"
#include "branch.hpp"
#include "tree.hpp"
#include "fruit.hpp"

using namespace std;

/* LINUX
#include <sys/time.h>
// zamiast #include <ctime>

int main() {
    struct timeval start, end;

    // Zapisz czas poczatkowy
    gettimeofday(&start, NULL);

    // To, co odpowiada za nawalanie operacji
    for (volatile int i = 0; i < 10000000; ++i) {}

    // Zapisz czas koncowy
    gettimeofday(&end, NULL);

    // Oblicz ile minelo
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds * 1000.0 + microseconds / 1000.0; // Convert to milliseconds

    // Przekaz na wyjscie
    std::cout << "Time elapsed: " << elapsed << " ms\n";

    return 0;
}
*/

int main() {

    {
        // #### ####

        bool drukuj_pomocnicze = true; // jesli pozadane sa jedynie liczby, ustawic na false

        // ### ###

        GARDEN_CLASS debug;
        debug.plantTree();
        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();
        debug.plantTree();
        debug.plantTree();

        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();

        debug.plantTree();
        debug.plantTree();
        debug.plantTree();

        debug.growthGarden();

        debug.plantTree();

        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();


        if (drukuj_pomocnicze) cout << "GARDEN" << endl << "TREES, BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << debug.getTreesTotal() << endl;
        cout << debug.getBranchesTotal() << endl;
        cout << debug.getFruitsTotal() << endl;
        cout << debug.getWeightsTotal() << endl << endl;


        if (drukuj_pomocnicze) cout << "CREATING TREE OUTSIDE OF GARDEN." << endl;


        TREE_CLASS solitary;

        solitary.growthTree();
        solitary.growthTree();
        solitary.growthTree();
        solitary.growthTree();
        solitary.growthTree();
        solitary.growthTree();


        if (drukuj_pomocnicze) cout << "SOLITARY TREE (6x grow)" << endl << "BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << solitary.getBranchesTotal() << endl;
        cout << solitary.getFruitsTotal() << endl;
        cout << solitary.getWeightsTotal() << endl << endl;

        solitary.growthTree();
        solitary.growthTree();
        solitary.growthTree();
        solitary.growthTree();
        solitary.growthTree();
        solitary.growthTree();


        if (drukuj_pomocnicze) cout << "SOLITARY TREE (12x grow [additional 6x since previous])" << endl << "BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << solitary.getBranchesTotal() << endl;
        cout << solitary.getFruitsTotal() << endl;
        cout << solitary.getWeightsTotal() << endl << endl;


        if (drukuj_pomocnicze) cout << "ATTEMPTING OPERATIONS." << endl;
        if (drukuj_pomocnicze) cout << "CLONING SOLITARY's 2ND BRANCH TO TREE:ID=3, ONLY AFTER" << endl
            << "CUTTING TREE:ID=3's 1ST BRANCH" << endl << endl;

        if (drukuj_pomocnicze) cout << "ATTEMPTING 'debug.getTreePointer(3)->getBranchPointer(3)->cutBranch(0)'" << endl << endl;


        debug.getTreePointer(3)->getBranchPointer(3)->cutBranch(0);


        if (drukuj_pomocnicze) cout << "RESULT:" << endl;

        if (drukuj_pomocnicze) cout << "GARDEN" << endl << "TREES, BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << debug.getTreesTotal() << endl;
        cout << debug.getBranchesTotal() << endl;
        cout << debug.getFruitsTotal() << endl;
        cout << debug.getWeightsTotal() << endl << endl;


        if (drukuj_pomocnicze) cout << "ATTEMPTING 'debug.getTreePointer(3)->cloneBranch(solitary.getBranchPointer(6))'" << endl << endl;

        if (drukuj_pomocnicze) cout << "ORIGIN BRANCH PTR: " << endl << endl;


        cout << solitary.getBranchPointer(6) << endl << endl;


        debug.getTreePointer(3)->cloneBranch(solitary.getBranchPointer(6));


        if (drukuj_pomocnicze) cout << "DESTINATION (POST-CLONE) BRANCH PTR: " << endl << endl;


        cout << debug.getTreePointer(3)->getBranchPointer(3) << endl << endl;


        if (drukuj_pomocnicze) cout << "THESE TWO POINTERS SHOULD BE DIFFERENT!" << endl << endl;


        if (drukuj_pomocnicze) cout << "RESULT:" << endl;

        if (drukuj_pomocnicze) cout << "GARDEN" << endl << "TREES, BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << debug.getTreesTotal() << endl;
        cout << debug.getBranchesTotal() << endl;
        cout << debug.getFruitsTotal() << endl;
        cout << debug.getWeightsTotal() << endl << endl;


        if (drukuj_pomocnicze) cout << "ATTEMPTING GROW 6x on GARDEN." << endl << endl;


        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();

        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();


        if (drukuj_pomocnicze) cout << "ATTEMPTING GROW 6x on SOLITARY TREE." << endl << endl;


        solitary.growthTree();
        solitary.growthTree();
        solitary.growthTree();

        solitary.growthTree();
        solitary.growthTree();
        solitary.growthTree();


        if (drukuj_pomocnicze) cout << "RESULT:" << endl;

        if (drukuj_pomocnicze) cout << "GARDEN" << endl << "TREES, BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << debug.getTreesTotal() << endl;
        cout << debug.getBranchesTotal() << endl;
        cout << debug.getFruitsTotal() << endl;
        cout << debug.getWeightsTotal() << endl << endl;


        if (drukuj_pomocnicze) cout << "SOLITARY TREE:" << endl << "BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << solitary.getBranchesTotal() << endl;
        cout << solitary.getFruitsTotal() << endl;
        cout << solitary.getWeightsTotal() << endl << endl;


        if (drukuj_pomocnicze) cout << "ATTEMPTING FADEBRANCH OPERATIONS VIA POINTERS." << endl << endl;

        if (drukuj_pomocnicze) cout << "ATTEMPTING FADEBRANCH on SOLITARY TREE:[BRANCH:HEIGHT=3, BRANCH:HEIGHT=9]." << endl << endl;


        solitary.getBranchPointer(3)->fadeBranch();
        solitary.getBranchPointer(9)->fadeBranch();

        if (drukuj_pomocnicze) cout << "RESULT: " << endl;

        if (drukuj_pomocnicze) cout << "SOLITARY TREE:" << endl << "BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << solitary.getBranchesTotal() << endl;
        cout << solitary.getFruitsTotal() << endl;
        cout << solitary.getWeightsTotal() << endl << endl;


        if (drukuj_pomocnicze) cout << "ATTEMPTING 2x FADEBRANCH on SOLITARY TREE:BRANCH:HEIGHT=9." << endl << endl;


        solitary.getBranchPointer(9)->fadeBranch();
        solitary.getBranchPointer(9)->fadeBranch();


        if (drukuj_pomocnicze) cout << "RESULT: " << endl;

        if (drukuj_pomocnicze) cout << "SOLITARY TREE:" << endl << "BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << solitary.getBranchesTotal() << endl;
        cout << solitary.getFruitsTotal() << endl;
        cout << solitary.getWeightsTotal() << endl << endl;


        if (drukuj_pomocnicze) cout << "ATTEMPTING EXTRACT on TREE:ID=2, TREE:ID=4." << endl << endl;

        debug.extractTree(2);

               



        if (drukuj_pomocnicze) cout << "RESULT AFTER 'debug.extractTree(2)': " << endl;

        if (drukuj_pomocnicze) cout << "GARDEN" << endl << "TREES, BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << debug.getTreesTotal() << endl;
        cout << debug.getBranchesTotal() << endl;
        cout << debug.getFruitsTotal() << endl;
        cout << debug.getWeightsTotal() << endl << endl;


        debug.extractTree(4);
        // debug.extractTree(6);
        // debug.plantTree();
        // debug.plantTree();
        // debug.plantTree();
        // debug.plantTree();
        // debug.plantTree();
        

        if (drukuj_pomocnicze) cout << "RESULT AFTER 'debug.extractTree(4)': " << endl;

        if (drukuj_pomocnicze) cout << "GARDEN" << endl << "TREES, BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << debug.getTreesTotal() << endl;
        cout << debug.getBranchesTotal() << endl;
        cout << debug.getFruitsTotal() << endl;
        cout << debug.getWeightsTotal() << endl << endl;


        if (drukuj_pomocnicze) cout << "ATTEMPTING TO CLONE TREE:ID=3 WITHIN GARDEN." << endl << endl;


        if (drukuj_pomocnicze) cout << "ORIGIN TREE PTR: " << endl << endl;


        cout << debug.getTreePointer(3) << endl << endl;


        debug.cloneTree(3);


        if (drukuj_pomocnicze) cout << "DESTINATION (POST-CLONE) TREE PTR: " << endl << endl;


        cout << debug.getTreePointer(2) << endl << endl;


        if (drukuj_pomocnicze) cout << "THESE TWO POINTERS SHOULD BE DIFFERENT!" << endl << endl;


        if (drukuj_pomocnicze) cout << "ATTEMPTING TO CLONE TREE:ID=2 WITHIN GARDEN." << endl << endl;


        if (drukuj_pomocnicze) cout << "ORIGIN TREE PTR: " << endl << endl;


        cout << debug.getTreePointer(2) << endl << endl;


        debug.cloneTree(2);


        if (drukuj_pomocnicze) cout << "DESTINATION (POST-CLONE) TREE PTR: " << endl << endl;


        cout << debug.getTreePointer(4) << endl << endl;


        if (drukuj_pomocnicze) cout << "THESE TWO POINTERS SHOULD BE DIFFERENT!" << endl << endl;

        if (drukuj_pomocnicze) cout << "RESULT:" << endl;

        if (drukuj_pomocnicze) cout << "GARDEN" << endl << "TREES, BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << debug.getTreesTotal() << endl;
        cout << debug.getBranchesTotal() << endl;
        cout << debug.getFruitsTotal() << endl;
        cout << debug.getWeightsTotal() << endl << endl;

        if (drukuj_pomocnicze) cout << "ATTEMPTING FADETREE OPERATIONS VIA POINTERS." << endl << endl;

        if (drukuj_pomocnicze) cout << "ATTEMPTING FADETREE 2x on TREE:ID=2." << endl << endl;

        debug.getTreePointer(2)->fadeTree();
        debug.getTreePointer(2)->fadeTree();


        if (drukuj_pomocnicze) cout << "RESULT:" << endl;

        if (drukuj_pomocnicze) cout << "GARDEN" << endl << "TREES, BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << debug.getTreesTotal() << endl;
        cout << debug.getBranchesTotal() << endl;
        cout << debug.getFruitsTotal() << endl;
        cout << debug.getWeightsTotal() << endl << endl;

        if (drukuj_pomocnicze) cout << "ATTEMPTING FADETREE 3x on TREE:ID=4." << endl << endl;

        debug.getTreePointer(4)->fadeTree();
        debug.getTreePointer(4)->fadeTree();

        if (drukuj_pomocnicze) cout << "RESULT:" << endl;

        if (drukuj_pomocnicze) cout << "GARDEN" << endl << "TREES, BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << debug.getTreesTotal() << endl;
        cout << debug.getBranchesTotal() << endl;
        cout << debug.getFruitsTotal() << endl;
        cout << debug.getWeightsTotal() << endl << endl;


        if (drukuj_pomocnicze) cout << "ATTEMPTING GROW 24x on GARDEN." << endl << endl;


        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();

        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();

        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();

        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();
        debug.growthGarden();


        if (drukuj_pomocnicze) cout << "RESULT:" << endl;

        if (drukuj_pomocnicze) cout << "GARDEN" << endl << "TREES, BRANCHES, FRUITS, WEIGHTS: " << endl;


        cout << debug.getTreesTotal() << endl;
        cout << debug.getBranchesTotal() << endl;
        cout << debug.getFruitsTotal() << endl;
        cout << debug.getWeightsTotal() << endl << endl;


        if (drukuj_pomocnicze) cout << "ARBITRARY NUM_FRUITS, WEIGHT CHECKS: " << endl << endl;


        cout << debug.getTreePointer(5)->getBranchPointer(3)->getFruitsTotal() << endl;
        cout << debug.getTreePointer(5)->getBranchPointer(3)->getFruitPointer(4)->getWeight() << endl;
        cout << debug.getTreePointer(4)->getBranchPointer(6)->getFruitsTotal() << endl;
        cout << debug.getTreePointer(4)->getBranchPointer(6)->getFruitPointer(2)->getWeight() << endl;
        cout << debug.getTreePointer(2)->getBranchPointer(9)->getFruitsTotal() << endl;
        cout << debug.getTreePointer(2)->getBranchPointer(9)->getFruitPointer(8)->getWeight() << endl << endl;


        if (drukuj_pomocnicze) {
            cout << "STRESS TEST (TIME ELAPSED)" << endl;

            int stressor_size = 5000;

            cout << "n = " << stressor_size << endl;
            cout << "Without .plantTree(): " << endl;

            clock_t start = clock();

            int i;
            for (i = 0; i < stressor_size; i++) {
                debug.growthGarden();
                debug.growthGarden();
                debug.growthGarden();
                debug.growthGarden();
                debug.growthGarden();
                debug.growthGarden();

                debug.getTreePointer(5)->getBranchPointer(3)->getFruitsTotal();
                debug.getTreePointer(5)->getBranchPointer(3)->getFruitPointer(4);
                debug.getTreePointer(4)->getBranchPointer(6)->getFruitsTotal();
                debug.getTreePointer(4)->getBranchPointer(6)->getFruitPointer(2)->getWeight();
                debug.getTreePointer(2)->getBranchPointer(9)->getFruitsTotal();
                debug.getTreePointer(2)->getBranchPointer(9)->getFruitPointer(8)->getWeight();

                debug.fadeGarden();
                debug.fadeGarden();
                debug.fadeGarden();
                debug.fadeGarden();
                debug.fadeGarden();
                debug.fadeGarden();
            }

            clock_t end = clock();

            double elapsed = 1000.0 * (end - start) / CLOCKS_PER_SEC;

            cout << "Time elapsed: " << elapsed << " ms" << endl;

            start = clock();

            cout << "With .plantTree(): " << endl;

            for (i = 0; i < stressor_size; i++) {
                debug.plantTree();

                debug.growthGarden();
                debug.growthGarden();
                debug.growthGarden();
                debug.growthGarden();
                debug.growthGarden();
                debug.growthGarden();

                debug.getTreePointer(5)->getBranchPointer(3)->getFruitsTotal();
                debug.getTreePointer(5)->getBranchPointer(3)->getFruitPointer(4);
                debug.getTreePointer(4)->getBranchPointer(6)->getFruitsTotal();
                debug.getTreePointer(4)->getBranchPointer(6)->getFruitPointer(2)->getWeight();
                debug.getTreePointer(2)->getBranchPointer(9)->getFruitsTotal();
                debug.getTreePointer(2)->getBranchPointer(9)->getFruitPointer(8)->getWeight();

                debug.fadeGarden();
                debug.fadeGarden();
                debug.fadeGarden();
                debug.fadeGarden();
                debug.fadeGarden();
                debug.fadeGarden();
            }

            end = clock();

            elapsed = 1000.0 * (end - start) / CLOCKS_PER_SEC;

            cout << "Time elapsed: " << elapsed << " ms" << endl;
        }
    }

    return 0;
}

/* OUTPUT
7
11
9
15

2
1
1

4
8
23

7
11
9
15

0x13331111111

0x24442222222

7
11
12
21

7
25
58
190

6
21
102

6
21
91

6
20
85

6
21
48
159

5
18
43
148

0x31113333333

0x41234444444

0x41234444444

0x52225555555

7
24
59
212

7
23
57
200

7
22
55
188

7
78
631
6766

15
27
13
24
11
15
*/