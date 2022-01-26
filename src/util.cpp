#include "util.h"

void readInput(vector<vector<pair<char, int>>> *mtx, vector<tuple<string, int, int>> *input) {
    char ch;
    string str;
    vector<pair<char, int>> temp;
    
    string f;
    cout << endl << "Masukkan nama file >> ";
    cin >> f;

    string file = "../test/";
    file += f;

    ifstream File(file);

    while(File.get(ch)) {
        if (ch == '-') {
            File.get(ch);
            break;
        }
        if (ch != ' ' && ch != '\n') {
            temp.push_back(make_pair(ch, -1));
        } else if (ch == '\n') {
            mtx->push_back(temp);
            temp.clear();
        }
    }

    while(getline(File, str)) {
        input->push_back(make_tuple(str, -1, -1));
    }

    File.close();
}

void printLightColor(int num) {
    if (num == 0) {
        cout << RED;
    } else if (num == 1) {
        cout << GREEN;
    } else if (num == 2) {
        cout << YELLOW;
    } else if (num == 3) {
        cout << BLUE;
    } else if (num == 4) {
        cout << MAGENTA;
    } else if (num == 5) {
        cout << CYAN;
    } else if (num == 6) {
        cout << BLACK;
    } else if (num == 7) {
        cout << WHITE;
    } else {
        cout << NORMAL;
    }
}

void printColor(int num) {
    if (num == 0) {
        cout << BOLDRED;
    } else if (num == 1) {
        cout << BOLDGREEN;
    } else if (num == 2) {
        cout << BOLDYELLOW;
    } else if (num == 3) {
        cout << BOLDBLUE;
    } else if (num == 4) {
        cout << BOLDMAGENTA;
    } else if (num == 5) {
        cout << BOLDCYAN;
    } else if (num == 6) {
        cout << BOLDBLACK;
    } else if (num == 7) {
        cout << BOLDWHITE;
    } else {
        cout << NORMAL;
    }
}

void check(vector<vector<pair<char, int>>> &mtx, vector<tuple<string, int, int>> &input, int &comp) {
    comp = 0;
    int color = 0;
    int n = mtx.size();
    int m = mtx[n-1].size();
    bool done;

    int l, i, j, k, length, temp, temp2, temppk;
    
    length = input.size();

    for (l = 0; l < length; l++) {
        // int pk = input[l].first.size();
        int pk = get<0>(input[l]).size();
        done = false;

        // KANAN
        for (i = 0; i < n && !done; i++) {
            for (j = 0; j < m && !done; j++) {
                k = 0;
                comp++;
                while((j+k < m) && (get<0>(input[l])[k] == mtx[i][j+k].first)) {
                    k++;
                    comp++;
                }
                if (k == pk) {
                    done = true;
                    for(temp = j; temp < j+k; temp++) {
                        mtx[i][temp].second = color % 8;
                        get<2>(input[l]) = color % 8;
                    }
                    get<1>(input[l]) = 1;
                    color += 1;
                }
            }
        }

        // KIRI
        for (i = n-1; i >= 0 && !done; i--) {
            for (j = m-1; j >= 0 && !done; j--) {
                k = 0;
                comp++;
                while((j-k >= 0) && (get<0>(input[l])[k] == mtx[i][j-k].first)) {
                    k++;
                    comp++;
                }
                if (k == pk) {
                    done = true;
                    for(temp = j; temp > j-k; temp--) {
                        mtx[i][temp].second = color % 8;
                        get<2>(input[l]) = color % 8;
                    }
                    get<1>(input[l]) = 2;
                    color += 1;
                }
            }
        }

        // ATAS
        for (j = 0; j < m && !done; j++) {
            for (i = n-1; i >= 0 && !done; i--) {
                k = 0;
                comp++;
                while((i-k >= 0) && (get<0>(input[l])[k] == mtx[i-k][j].first)) {
                    k++;
                    comp++;
                }
                if (k == pk) {
                    done = true;
                    for(temp = i; temp > i-k; temp--) {
                        mtx[temp][j].second = color % 8;
                        get<2>(input[l]) = color % 8;
                    }
                    get<1>(input[l]) = 3;
                    color += 1;
                }
            }
        }

        // BAWAH
        for (j = 0; j < m && !done; j++) {
            for (i = 0; i < n && !done; i++) {
                k = 0;
                comp++;
                while((i+k < n) && (get<0>(input[l])[k] == mtx[i+k][j].first)) {
                    k++;
                    comp++;
                }
                if (k == pk) {
                    done = true;
                    for(temp = i; temp < i+k; temp++) {
                        mtx[temp][j].second = color % 8;
                        get<2>(input[l]) = color % 8;
                    }
                    get<1>(input[l]) = 4;
                    color += 1;
                }
            }
        }

        // KANAN ATAS
        for (i = 0; i < n && !done; i++) {
            for (j = 0; j < m && !done; j++) {
                k = 0;
                comp++;
                while((i-k >= 0) && (j+k < m) && (get<0>(input[l])[k] == mtx[i-k][j+k].first)) {
                    k++;
                    comp++;
                }
                if (k == pk) {
                    done = true;
                    temp = i;
                    temp2 = j;
                    for (temppk = 0; temppk < pk; temppk++) {
                        mtx[temp][temp2].second = color % 8;
                        get<2>(input[l]) = color % 8;
                        temp--;
                        temp2++;
                    }
                    get<1>(input[l]) = 5;
                    color += 1;
                }
            }
        }

        // KANAN BAWAH
        for (i = 0; i < n && !done; i++) {
            for (j = 0; j < m && !done; j++) {
                k = 0;
                comp++;
                while((i+k < n) && (j+k < m) && (get<0>(input[l])[k] == mtx[i+k][j+k].first)) {
                    k++;
                    comp++;
                }
                if (k == pk) {
                    done = true;
                    temp = i;
                    temp2 = j;
                    for (temppk = 0; temppk < pk; temppk++) {
                        mtx[temp][temp2].second = color % 8;
                        get<2>(input[l]) = color % 8;
                        temp++;
                        temp2++;
                    }
                    get<1>(input[l]) = 6;
                    color += 1;
                }
            }
        }

        // KIRI ATAS
        for (i = 0; i < n && !done; i++) {
            for (j = 0; j < m && !done; j++) {
                k = 0;
                comp++;
                while((i-k >= 0) && (j-k >= 0) && (get<0>(input[l])[k] == mtx[i-k][j-k].first)) {
                    k++;
                    comp++;
                }
                if (k == pk) {
                    done = true;
                    temp = i;
                    temp2 = j;
                    for (temppk = 0; temppk < pk; temppk++) {
                        mtx[temp][temp2].second = color % 8;
                        get<2>(input[l]) = color % 8;
                        temp--;
                        temp2--;
                    }
                    get<1>(input[l]) = 7;
                    color += 1;
                }
            }
        }

        // KIRI BAWAH
        for (i = 0; i < n && !done; i++) {
            for (j = 0; j < m && !done; j++) {
                k = 0;
                comp++;
                while((i+k < n) && (j-k >= 0) && (get<0>(input[l])[k] == mtx[i+k][j-k].first)) {
                    k++;
                    comp++;
                }
                if (k == pk) {
                    done = true;
                    temp = i;
                    temp2 = j;
                    for (temppk = 0; temppk < pk; temppk++) {
                        mtx[temp][temp2].second = color % 8;
                        get<2>(input[l]) = color % 8;
                        temp++;
                        temp2--;
                    }
                    get<1>(input[l]) = 8;
                    color += 1;
                }
            }
        }
    }
}

void printResult(vector<vector<pair<char, int>>> mtx, vector<tuple<string, int, int>> input) {
    int n = mtx.size();
    int m = mtx[n-1].size();
    cout << endl << CYAN << "----- Hasil Word Search Puzzle -----" << NORMAL << endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printColor(mtx[i][j].second);
            cout << mtx[i][j].first << " " << NORMAL;
        }
        cout << endl;
    }
    cout << endl << CYAN << "----- DETAIL -----" << NORMAL << endl;

    for (int i = 0; i < input.size(); i++) {
        cout << "Kata ";
        printLightColor(get<2>(input[i]));
        cout << get<0>(input[i]) << NORMAL << " ditemukan dengan arah " << MAGENTA;
        if (get<1>(input[i]) == 1) {
            cout << "ke kanan" << endl;
        } else if (get<1>(input[i]) == 2) {
            cout << "ke kiri" << endl;
        } else if (get<1>(input[i]) == 3) {
            cout << "ke atas" << endl;
        } else if (get<1>(input[i]) == 4) {
            cout << "ke bawah" << endl;
        } else if (get<1>(input[i]) == 5) {
            cout << "diagonal kanan atas" << endl;
        } else if (get<1>(input[i]) == 6) {
            cout << "diagonal kanan bawah" << endl;
        } else if (get<1>(input[i]) == 7) {
            cout << "diagonal kiri atas" << endl;
        } else if (get<1>(input[i]) == 8) {
            cout << "diagonal kiri bawah" << endl;
        } else {
            cout << "ERROR" << endl;
        }
        cout << NORMAL;
    }
    cout << endl;
}