import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
import random


k = pd.read_csv("probarK.csv", delimiter=',')
n = pd.read_csv("optimizado.csv", delimiter=',')



df = pd.DataFrame({'K': k['x'], 'N': n['x']}, index = n['y'])

indxM = []
for i in range(10,500):
	if i % 5 == 0:
		indxM.append(i)
#fb.plot()
#bp.plot()
plt.plot(k['y'],k['x'],'g.', label='Crecimiento en funcion del crecimiento de K')
plt.plot(n['y'],n['x'],'b.', label='Crecimiento en funcion del crecimiento de N')


legend = plt.legend(loc='upper center', shadow=True)
frame = legend.get_frame()
frame.set_facecolor('0.90')
for label in legend.get_texts():
    label.set_fontsize('medium')

for label in legend.get_lines():
    label.set_linewidth(1.5)

plt.ylabel("Tiempo en segundos")
plt.show()
