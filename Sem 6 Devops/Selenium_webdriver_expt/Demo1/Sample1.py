from selenium import webdriver
import time
from selenium.webdriver.common.keys import Keys

print("Sample test case started")

driver = webdriver.Chrome()
driver.maximize_window()
driver.get("https://www.google.com/")

driver.find_element(by="name", value="q").send_keys("javatpoint")
time.sleep(3)

driver.find_element(by="name", value="btnK").send_keys(Keys.ENTER)
time.sleep(3)

driver.close()

print("Sample test case successfully completed")
