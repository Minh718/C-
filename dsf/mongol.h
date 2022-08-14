string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
string p;
for (int i = 0; i < N1; i++) {
    string s, l;
    for (int j = 0; j < input1[i].size(); j += 2) {
        if (input1[i][j] == '0' && input1[i][j + 1] == '1') {
            s += '1';
        }
        else if (input1[i][j] == '0' && input1[i][j + 1] == '0') {
            s += '0';
        }
        else if (input1[i][j] == '1' && input1[i][j + 1] == '1') {
            s += '3';
        }
        else if (input1[i][j] == '1' && input1[i][j + 1] == '0') {
            s += '2';
        }
        if (input1[i][j + 2] == ' ') {
            j++;
            s += ' ';
        }
    }
    string q = "EFGHIJKLMNOPQR#TUVWXY@ASZBCD";
    int so = -1;
    for (int k = 0; k < s.size(); k++) {
        if (s[k] == '0') {
            so++;
            if (so >= 7) {
                so -= 7;
            }
            if ((s[k + 1] == ' ') || (k == s.size() - 1)) {
                l += q[so]; k++; so = -1;
            }
        }
        if (s[k] == '1') {
            so++;
            if (so >= 7) {
                so -= 7;
            }
            if ((s[k + 1] == ' ') || (k == s.size() - 1)) {
                l += q[7 + so]; k++; so = -1;
            }
        }
        if (s[k] == '2') {
            so++;
            if (so >= 7) {
                so -= 7;
            }
            if ((s[k + 1] == ' ') || (k == s.size() - 1)) {
                l += q[7 * 2 + so]; k++; so = -1;
            }
        }
        if (s[k] == '3') {
            so++;
            if (so >= 7) {
                so -= 7;
            }
            if ((s[k + 1] == ' ') || (k == s.size() - 1)) {
                l += q[7 * 3 + so]; k++; so = -1;
            }
        }
    }
    int e = 1;
    for (int j = 0; j < l.size(); j++) {
        if (l[j] == '#' && l[j + 1] != '#') {
            for (; j < l.size(); j++) {
                if (l[j + 1] == '#' || l[j + 1] == '@') {
                    char v = l[j] + 1;
                    l.insert(l.begin() + j + 1, v);
                    j++;
                    if (l[j + 1] == '@') {
                        e = j + 2;
                        break;
                    }
                }
                if (j == l.size() - 1 && l[l.size() - 1] != '#' && l[l.size() - 1] != '@') {
                    l += l[l.size() - 1] + 1;
                    j++;
                }
            }
        }
        if (l[j] == '@' && l[j + 1] != '@') {
            int h = j + 1; e = j + 1;
            for (; j < l.size(); j++) {
                if (l[j + 1] == '#' || l[j + 1] == '@') {
                    int k = j;
                    e = j + 2;
                    for (int m = h; m <= k; m++) {
                        char v = l[m];
                        l[m] = l[k];
                        l[k] = v;
                        k--;
                    }
                    if (l[j + 1] == '#') {
                        break;
                    }
                }
                if (j == l.size() - 1 && l[l.size() - 1] != '#' && l[l.size() - 1] != '@') {
                    int cd = l.length();
                    for (int z = e; z < cd; z++) {
                        char v = l[z];
                        l[z] = l[cd - 1];
                        l[cd - 1] = v;
                        cd--;
                    }
                }
            }
        }
    }
    for (int j = 0; j < l.size(); j++) {
        if (l[j] == '@' || l[j] == '#') {
            l.erase(l.begin() + j);
            j--;
        }
    }
    for (int ii = 0; ii < NID; ii++) {
        for (int j = 0; j < ID[ii].size()-4; j++) {
            if (ID[ii][0] == 'V' && ID[ii][1] == 'U' && ID[ii][2] == 'A' && j == 0) {
                int qq = l.size();
                string ss, sss;
                if (qq % 2 != 0) {
                    for (int k = qq - 1; k >= 0; k--) {
                        ss += l[k];
                    }
                }
                else {
                    ss = l;
                    for (int k = 0; k < qq; k += 2) {
                        char xx = ss[k];
                        ss[k] = ss[qq - 2];
                        ss[qq - 2] = xx;
                        qq -= 2;
                    }
                    qq = l.length();
                    for (int k = 1; k < qq; k += 2) {
                        char xx = ss[k];
                        ss[k] = ss[qq - 1];
                        ss[qq - 1] = xx;
                        qq -= 2;
                    }
                }
                for (int k = 0; k < l.size(); k++) {
                    if (ss[k] > l[k]) {
                        sss += ss[k];
                    }
                    else {
                        sss += l[k];
                    }
                }
                l = sss;

            }
            if (ID[ii][j + 1] == 'T' && ID[ii][j + 2] == 'H' && ID[ii][j + 3] == 'D') {
                int x = -1;
                for (int m = 0; m < l.size(); m++) {
                    x++;
                    if (x == 0) {
                        l.erase(l.begin() + m);
                        x = -3;
                        m--;
                    }
                }
                for (int m = 0; m < l.size(); m++) {
                    for (int k = m + 1; k < l.size(); k++) {
                        if (l[m] > l[k]) {
                            char x = l[m];
                            l[m] = l[k];
                            l[k] = x;
                        }
                    }
                }
            }
        }

    }
    if(i==N1-1){
        p+=l;
    }
    else{
    p += l + ' ';
    }
}
return p;
}
