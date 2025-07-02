# 🔍 Auto Web Search with Selenium

This Python project automates web searches using **Selenium WebDriver**. It launches a browser, enters search queries into a search engine (e.g., Google or Bing), and retrieves results automatically.

## 🚀 Features

- Opens a browser and performs search queries
- Supports Google or Bing (can be customized)
- Extracts search result titles and URLs
- Simple and easy-to-extend Python script

## 🧰 Requirements

- Python 3.x
- [Selenium](https://pypi.org/project/selenium/)
- WebDriver (e.g., ChromeDriver or GeckoDriver) installed and in system PATH

Install dependencies:

```bash
pip install selenium
```

Download the appropriate WebDriver for your browser:

- [ChromeDriver](https://sites.google.com/chromium.org/driver/)
- [GeckoDriver (Firefox)](https://github.com/mozilla/geckodriver/releases)

## 🧪 Example Usage

```python
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

driver = webdriver.Chrome()  # or Firefox()

driver.get("https://www.google.com")
search_box = driver.find_element(By.NAME, "q")
search_box.send_keys("Selenium Python automation")
search_box.send_keys(Keys.RETURN)

time.sleep(3)  # wait for results to load
results = driver.find_elements(By.CSS_SELECTOR, "h3")

for result in results:
    print(result.text)

driver.quit()
```

## 📁 Structure

```
auto-web-search/
├── search.py
├── README.md
└── requirements.txt
```
