import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
import random


r = pd.read_csv("MuchasR.csv", delimiter=',')

plt.plot(r['y'],r['x'],'g.', label='Crecimiento en de M')

legend = plt.legend(loc='upper center', shadow=True)
frame = legend.get_frame()
frame.set_facecolor('0.90')
for label in legend.get_texts() :
    label.set_fontsize('medium')

for label in legend.get_lines():
    label.set_linewidth(1.5)


plt.ylabel("Tiempo en segundos")
plt.xlabel("Cantidad de Rutas total")
plt.show()
