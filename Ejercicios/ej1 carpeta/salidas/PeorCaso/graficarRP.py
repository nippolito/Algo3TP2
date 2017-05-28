import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
import random


rs = pd.read_csv("MuchasRS.csv", delimiter=',')

plt.plot(rs['y'],rs['x'],'b.', label='Crecimiento en funcion del crecimiento de Cantidad de Rutas Premium')

legend = plt.legend(loc='upper center', shadow=True)
frame = legend.get_frame()
frame.set_facecolor('0.90')
for label in legend.get_texts() :
    label.set_fontsize('medium')

for label in legend.get_lines():
    label.set_linewidth(1.5)


plt.ylabel("Tiempo en segundos")
plt.xlabel("Cantidad De Rutas Premium Total")
plt.show()
