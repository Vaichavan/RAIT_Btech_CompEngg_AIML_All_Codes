from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import time

print("Sample test case started")

# Configure Chrome options
chrome_options = Options()
chrome_options.add_argument("user-agent=Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.51 Safari/537.36")
chrome_options.add_argument("--disable-blink-features=AutomationControlled")  # Prevent detection

# Initialize WebDriver
driver = webdriver.Chrome(options=chrome_options)
driver.maximize_window()
driver.get("https://www.google.com/")

# Search for 'simplilearn'
search_box = driver.find_element(By.NAME, "q")
search_box.send_keys("simplilearn")
time.sleep(2)
search_box.send_keys(Keys.ENTER)
time.sleep(3)

# Get search result snippets
results = driver.find_elements(By.CSS_SELECTOR, ".tF2Cxc .VwiC3b")

# Print the first few snippets
for i, result in enumerate(results[:5]):  # Adjust the number as needed
    print(f"Result {i+1}: {result.text}\n")

# Close the browser
driver.quit()

print("Sample test case successfully completed")
