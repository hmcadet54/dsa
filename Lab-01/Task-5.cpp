#include <iostream>
using namespace std;

class Friend_Check
{
    bool friendshipMatrix[5][5] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}};
        public:
        
        void check()
        {
            for (int i=0; i<5;i++)
            {
                cout<<"Friengs on Line["<<i+1<<"]: ";
                for (int j=0; j<5;j++)
                {
                    if (friendshipMatrix[i][j] == 1){
                        cout <<j<<", ";
                    }
                }
                cout << endl;
            }

        }
};
int main()
{
    Friend_Check fc;
    fc.check();
    return 0;
}