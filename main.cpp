
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct FinancialData {
    double revenue, cogs, opex, taxes;
    double assets, liabilities, equity;
    double cfop, cfinv, cffin;
};

FinancialData readInput() {
    FinancialData f;
    ifstream fin("input.txt");
    fin >> f.revenue >> f.cogs >> f.opex >> f.taxes;
    fin >> f.assets >> f.liabilities >> f.equity;
    fin >> f.cfop >> f.cfinv >> f.cffin;
    fin.close();
    return f;
}

void generateReports(FinancialData f) {
    double gross = f.revenue - f.cogs;
    double op = gross - f.opex;
    double net = op - f.taxes;

    // ✅ Division safety
    double netMargin = (f.revenue != 0) ? (net / f.revenue) * 100 : 0;
    double roa = (f.assets != 0) ? (net / f.assets) * 100 : 0;
    double dte = (f.equity != 0) ? f.liabilities / f.equity : 0;
    double netCash = f.cfop + f.cfinv + f.cffin;

    ofstream income("output/income_statement.txt");
    income << "Income Statement\n";
    income << "Revenue: " << f.revenue << "\n";
    income << "COGS: " << f.cogs << "\n";
    income << "Gross Profit: " << gross << "\n";
    income << "Operating Expenses: " << f.opex << "\n";
    income << "Net Profit: " << net << "\n";
    income.close();

    ofstream balance("output/balance_sheet.txt");
    balance << "Balance Sheet\n";
    balance << "Assets: " << f.assets << "\n";
    balance << "Liabilities: " << f.liabilities << "\n";
    balance << "Equity: " << f.equity << "\n";
    balance << "Assets = Liabilities + Equity? " 
            << (f.assets == f.liabilities + f.equity ? "✔" : "❌") << "\n";
    balance.close();

    ofstream cash("output/cash_flow.txt");
    cash << "Cash Flow Statement\n";
    cash << "Operating: " << f.cfop << "\n";
    cash << "Investing: " << f.cfinv << "\n";
    cash << "Financing: " << f.cffin << "\n";
    cash << "Net Cash Flow: " << netCash << "\n";
    cash.close();

    cout << fixed << setprecision(2);
    cout << "✅ Reports Generated:\n";
    cout << "- Net Profit Margin: " << netMargin << "%\n";
    cout << "- ROA: " << roa << "%\n";
    cout << "- Debt-to-Equity: " << dte << "\n";
    cout << "📁 Check output/ folder for full statements.\n";
}

int main() {
    FinancialData f = readInput();
    generateReports(f);
    return 0;
}
