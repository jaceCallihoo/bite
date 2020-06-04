
vector<Line> parse(vector<string> input) {

    vector<Line> ret;   // the return vector
    
    // (token -> value) map
    unordered_map<string,char> codeMap = { {"ADD",ADD}, {"AND",AND}, {"OR",OR}, {"BEQ",BEQ}, {"SL",SL}, {"SR",SR},{"J",J}, {"MOV",MOV}, {"LW",LW}, {"SW",SW} };
    cout << "created map" << endl;


    // tokenize the input
    for (string s : input) {

        // Tokenize input
        vector<string> token;
        for (auto i = strtok(&s[0], " "); i != NULL; i = strtok(NULL, " "))
            token.push_back(i);

        validateLine(token);


        cout << "created token:" << endl;

        for (string s : token) {
            cout << s << endl;
        }


        // use the tokens to create line objects
        
        Line::arg al[3];
        al[0] = Line::arg(token[1]);
        al[1] = Line::arg(token[2]);
        al[2] = Line::arg(token[3]);
        Line l((byte)codeMap[token[0]], al[0], al[1], al[2]);

        // ret.push_back(Line((byte)codeMap[token[0]], Line::arg(token[1]), Line::arg(token[2]), Line::arg(token[3])));

        ret.push_back(l);

        cout << endl << endl;
    }

    return ret;
}


Line::arg::arg() {
    regFlag = false;
    val = 0;
}

Line::arg::arg(string s) {

    cout << "\nstoi\n" << s << endl << s[0] << endl;

    if (s[0] == '$') {
        cout << "register" << endl;
        regFlag = true;
        val = stoi(s.substr(1, s.size() - 1));
        cout << "stoi check" << endl;
    } else {
        cout << "number" << endl;
        regFlag = false;
        val = stoi(s);
        cout << "stoi check" << endl;
    }
}


Line::Line(byte in, arg a0, arg a1, arg a2) {
    instruction = in;
    al[0] = a0;
    al[1] = a1;
    al[2] = a2;
}

// Line::arg &Line::arg::operator=(const Line::arg &a) {
//     regFlag = a.regFlag;
//     val = a.val;
// }

// void Line::execute() {

//     switch (instruction)
//     {
//     case ADD:
//         reg[ri[0]] = reg[ri[1]] + reg[ri[2]];
//         pc++;
//         break;
    
//     case AND:
//         reg[ri[0]] = reg[ri[1]] & reg[ri[2]];
//         pc++;
//         break;

//     case OR:
//         reg[ri[0]] = reg[ri[1]] | reg[ri[2]];
//         pc++;
//         break;

//     case BEQ:
//         if (reg[ri[1]] == reg[ri[2]]) pc = reg[ri[0]];
//         break;

//     case SL:
//         reg[ri[0]] = reg[ri[1]] << reg[ri[2]];
//         pc++;
//         break;

//     case SR:
//         reg[ri[0]] = reg[ri[1]] >> reg[ri[2]];
//         pc++;
//         break;

//     case J:
//         pc = reg[ri[0]];
//         break;

//     case MOV:
//         reg[ri[0]] = reg[ri[1]];
//         pc++;
//         break;

//     case LW:
//         reg[ri[0]] = mem[reg[1]];
//         pc++;
//         break;

//     case SW:
//         mem[ri[0]] = reg[ri[1]];
//         pc++;
//         break;

//     default:
//         printf("ERROR: Line object created with incorrect instruction name");;
//     }
// }


// void tokenize(string const &str, const char delim, vector<string> &out)
// {
// 	size_t start;
// 	size_t end = 0;

// 	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
// 	{
// 		end = str.find(delim, start);
// 		out.push_back(str.substr(start, end - start));
// 	}
// }

