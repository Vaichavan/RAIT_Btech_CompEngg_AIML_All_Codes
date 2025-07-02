import pandas as pd
import matplotlib.pyplot as plt

author = ['Vaibhav', 'OM', 'Soham']
article_counts = [5, 7, 10]
age = [29, 34, 40]

author_series = pd.Series(author)
article_series = pd.Series(article_counts)

data = {
    "Author": author_series,
    "Articles": article_series,
    "Age": pd.Series(age)
}
df = pd.DataFrame(data)

print(df)

df.plot.bar(x="Author", y=["Articles", "Age"], rot=0)
plt.xlabel("Author")
plt.ylabel("Count")
plt.title("Articles and Age of Authors")
plt.show()
