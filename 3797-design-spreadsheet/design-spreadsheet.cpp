class Spreadsheet {
public:
    int rows;
    unordered_map<string, int> cells;

    Spreadsheet(int rows) {
        this->rows = rows;
    }
    
    void setCell(string cell, int value) {
        cells[cell] = value;
    }
    
    void resetCell(string cell) {
        cells.erase(cell);
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);
        int plus = formula.find('+');
        string a = formula.substr(0, plus);
        string b = formula.substr(plus + 1);

        auto val = [&](string s) {
            return all_of(s.begin(), s.end(), ::isdigit) ? stoi(s) : cells[s];
        };

        return val(a) + val(b);
    }
};