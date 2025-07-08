# 🧾 FinSheet — Mini Financial Report Generator

**FinSheet** is a lightweight, beginner-friendly finance tool built using **C++** and a basic **HTML/CSS** interface. It generates structured financial reports from user-provided business inputs — ideal for students, interview demos, and finance learners.

> 🔗 [Live Demo (HTML Form)](https://alive-charm33.github.io/FinSheet/)  
> 📁 [Source Code](https://github.com/alive-charm33/FinSheet)

---

## 📊 Features

- ✅ Income Statement Generator
- ✅ Balance Sheet Verifier (Assets = Liabilities + Equity)
- ✅ Cash Flow Statement
- ✅ Net Profit Margin, ROA, Debt-to-Equity Calculations
- ✅ Generates `*.txt` output reports for real-world feel

---

## 🛠️ Tech Stack

| Language | Purpose |
|----------|---------|
| `C++` | Handles core calculations, input/output, logic |
| `HTML/CSS` | Collects user data via form |
| `Plain Text Files` | Used instead of a database (simpler + offline) |

---

## 🗂️ How It Works

1. 📝 User enters business data in the HTML form  
2. 📁 Form writes input to `input.txt`  
3. ⚙️ `main.cpp` processes the data using file I/O  
4. 📊 Generates:
    - `income_statement.txt`
    - `balance_sheet.txt`
    - `cash_flow.txt` (inside `output/`)
