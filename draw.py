import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('results.csv')
plt.figure(figsize=(10, 6))

plt.plot(df['Size'], df['Linear'], label='Линейный поиск', marker='o', linewidth=2)
plt.plot(df['Size'], df['BinTree'], label='Бинарное дерево', marker='s', linewidth=2)
plt.plot(df['Size'], df['RBTree'], label='Красно-черное дерево', marker='^', linewidth=2)
plt.plot(df['Size'], df['HashTable'], label='Хэш-таблица', marker='d', linewidth=2)

plt.yscale('log')
plt.xscale('log')

plt.xlabel('Количество элементов (Log Scale)', fontsize=12)
plt.ylabel('Время поиска, сек (Log Scale)', fontsize=12)
plt.title('Сравнение алгоритмов поиска', fontsize=14, fontweight='bold')
plt.legend()
plt.grid(True, which="both", ls="--", alpha=0.5)

plt.tight_layout()
plt.savefig('search_performance.png', dpi=300)
plt.show()