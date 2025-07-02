# RAIT_BTech_CompEngg_with_AIML_Minor_All_Practical_Codes

A one‑stop, **open‑source** collection of every practical program, notebook, and lab artifact I (Vaichavan) wrote while pursuing  
**B.Tech. Computer Engineering with an AIML Minor at Ramrao Adik Institute of Technology (RAIT)**.

> **Why publish this?**  
> - To help current and future RAIT students get a head‑start on lab work.  
> - To document my personal learning journey semester‑by‑semester.  
> - To give back to the wider academic community—feel free to fork, learn, or contribute!

---

## 📁 Repository Layout

| Semester | Folder | Core Subjects Covered | Highlights |
|----------|--------|-----------------------|------------|
| **Sem 1** | `Sem1/C_Programming` | Structured & modular programming in C | Classic lab problems, pointer drills, file I/O, mini projects |
|          | `Sem1/TurboC_Programming` | DOS‑based Turbo C specifics | Same programs rewritten for the Turbo C 3.0 toolchain |
| **Sem 2** | `Sem2/Python_Codes` | Python basics to OOP | 25+ scripts: data structures, files, Tkinter GUI, Pandas mini‑labs |
| **Sem 3** | `Sem3/DAA` | Design & Analysis of Algorithms | Recursive vs. iterative solutions, time analysis comments |
|          | *(dup folder kept for legacy)* | – | – |
| **Sem 5** *(Minor)* | `Sem5/Fundamentals_of_ML` | ML foundations (scikit‑learn) | Logistic Reg, DT, NB, SVM, K‑Means notebooks + PDF outputs |
| **Sem 6** *(Minor)* | `Sem6/Artificial_Intelligence` | Classical AI | Search, logic, fuzzy sets, MiniMax demos |
|          | `Sem6/Machine_Learning_Practicals` | Hands‑on ML | Cleaned notebooks, datasets (`penguins.csv`, solar‑radiation study) |
|          | `Sem6/Soft_Computing` | ANN, fuzzy, GA | Jupyter & `.py` examples, detailed markdown notes |
|          | `Sem6/DevOps` | CI/CD, Docker, Selenium | Jenkins pipeline files, Selenium tests, Dockerfile, HTML samples |

*(Timestamps in commit history show these were uploaded in a single “initial commit” burst; source work spans 2022‑2025.)*

---

## 🚀 Quick Start

1. **Clone**  
   ```bash
   git clone https://github.com/<your‑username>/RAIT_BTech_CompEngg_with_AIML_Minor_All_Practical_Codes.git
   cd RAIT_BTech_CompEngg_with_AIML_Minor_All_Practical_Codes
   ```

2. **Build/Run C & C++ Codes**

   ```bash
   # GCC / MinGW (recommended)
   gcc Sem1/C_Programming/1_merge.c -o merge
   ./merge
   # Turbo C .EXE (legacy)
   ```

3. **Run Python Scripts / Notebooks**

   ```bash
   # Create environment
   python -m venv venv
   source venv/bin/activate         # Windows: venv\Scripts\activate
   pip install -r requirements.txt  # Mostly for ML + Jupyter
   # Scripts
   python Sem2/Python_Codes/4_factorial.py
   # Notebooks
   jupyter notebook
   ```

4. **DevOps Demos**  
   *See* `Sem6/DevOps/README.md` for Jenkins job XML, Docker build steps, and Selenium WebDriver usage.

---

## 🛠️ Prerequisites

| Language / Tool  | Tested Version(s)                  | Notes                                                           |
| ---------------- | ---------------------------------- | --------------------------------------------------------------- |
| **C / C++**      | GCC 11+, Turbo C 3.0               | Turbo C required only for DOS‑specific labs                     |
| **Python**       | 3.10.x (recommended), 3.12.x works | All scripts are version‑agnostic; ML notebooks verified on 3.10 |
| **Jupyter**      | Notebook 7+ / JupyterLab           | For `.ipynb` experiments                                        |
| **scikit‑learn** | 1.4+                               | ML & AI practicals                                              |
| **Docker**       | 25+                                | DevOps labs                                                     |
| **Jenkins**      | 2.440+ LTS                         | Declarative pipelines                                           |
| **Selenium**     | 4.21+                              | Web driver exercises                                            |

---

## 📚 How to Navigate

* Each folder contains its **own mini‑README** with:
  * Lab aim / objective
  * Steps / algorithm
  * Expected output screenshots or PDFs
  * References

* File names mirror university experiment numbers, e.g.  
  `expt6‑huffman.c`, `EXP‑5_NaiveBayes.ipynb`.

* **Datasets** live alongside notebooks to maintain relative paths.

---

## 🤝 Contributing

1. Fork → Create branch → Commit → Pull Request.  
2. Please keep commit messages consistent with:  
   `SemX: <Subject> – <Short description>`  
3. Add screenshots / output samples when fixing or updating a lab.  
4. Respect academic integrity—_do not_ submit these verbatim for assessment.

---

## 📄 License

Unless stated otherwise in a sub‑folder, all code and notebooks (c) **Vaichavan** are released under the **MIT License**.  
Feel free to use, adapt, and share with attribution.

---

## 🙏 Acknowledgements

* Faculty & lab instructors at **RAIT, Navi Mumbai**  
* Open‑source communities: GCC, Python, scikit‑learn, Jupyter, Docker, Jenkins, Selenium  
* Classmates who debugged edge‑cases at 3 a.m.!

> **Star** ⭐ the repo if it helped you, and drop an issue or PR if you spot improvements.
