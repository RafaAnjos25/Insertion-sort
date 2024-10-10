import matplotlib.pyplot as plt
import numpy as np

# Dados dos tempos
tempos_ordenados = [0.55, 0.52, 0.53, 0.52, 0.52, 0.52, 0.53, 0.55, 0.52, 0.52]
tempos_invertidos = [1.08, 1.11, 1.07, 1.08, 1.08, 1.08, 1.12, 1.08, 1.09, 1.11]
tempos_aleatorios = [841.16, 841.16, 831.15, 841.16, 841.16, 831.15, 831.15, 831.15, 841.16, 831.15]

# Cálculo das médias
media_ordenados = np.mean(tempos_ordenados)
media_invertidos = np.mean(tempos_invertidos)
media_aleatorios = np.mean(tempos_aleatorios) / 1000  # Convertendo aleatório para segundos

# Preparando os dados para o gráfico
categorias = ['Vetor com\n50.000 números\nordenados', 
              'Vetor com\n50.000 números\ninvertidos', 
              'Vetor com\n50.000 números\naleatórios']
medias = [media_ordenados, media_invertidos, media_aleatorios]  # Valores em segundos

# Criando o gráfico de linha
fig, ax = plt.subplots()
ax.plot(categorias, medias, marker='o', color='black', linestyle='-', linewidth=2)

# Títulos e rótulos
ax.set_title('Média do Tempo de Execução em Segundos')
ax.set_ylabel('Tempo (segundos)')
ax.set_ylim([0, 2])  # Define os limites do eixo y para 2 segundos

# Adicionando os valores nos gráficos
for i, v in enumerate(medias):
    ax.text(i, v + 0.05, f'{v:.3f} s', ha='center', color='black')

# Salvando o gráfico como imagem
plt.tight_layout()
plt.savefig('grafico_media_tempo_execucao_segundos.png')

print("Gráfico salvo como 'grafico_media_tempo_execucao_segundos.png'")
