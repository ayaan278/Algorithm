//#include "../../Common/dataSet1.h"
//
//
//
//void dataSet1::interface()
//{
//    int size;
//    // this path is invalid, you need to change it to the main branch's path. Similarly, change all the mentioned paths at the Notations section
//    string fileName = ""; // path for the directory where 'csv' must be located
//
//
//    while(true){
//        cout << "State the intended functionality " << endl;
//        cout << "1. For generating data sets" << endl;
//        cout << "2. For merge sorting" << endl;
//        cout << "3. For heap sorting\n\n\n" << endl;
//
//        cin >> option;
//
//        switch(option)
//        {
//            // generates data sets
//            case 1:
//                cout << "enter the size of the file" << endl;
//                cin >> size;
//                fileName = ""; // path for the directory where 'csv' must be located
//                dataSet1::craftData(fileName, dataSet1::v1, size);
//                system("cls");
//                cout << "data sample have being successfully generated" << endl;
//                break;
//            // merge sorting an existed data sets
//            case 2:
//                cout << "Enter the size of file" << endl;
//                cin >> size;
//                dataSet1::mergeSortSetup(size);
//                system("cls");
//                cout << "file have being successfully sorted" << endl;
//                break;
//
//            // heap sorting an existed data sets
//            case 3:
//
//                system("cls");
//                cout << "file have being successfully sorted" << endl;
//
//
//            // handle invalid input
//            default:
//                cout << "please enter a valid option" << endl;
//                system("cls");
//                break;
//        }
//    }
//}