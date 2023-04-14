<h1 align="center">
	✏️ Cub3D
</h1>

<p align="center"><br>
Esse projeto é inspirado pelo jogo Wolfenstein 3D, que foi o primeiro FPS. Ele explora ray-casting. O objetivo é fazer uma representação dinâmica de dentro de um labirinto.<br>
This project is inspired by the Wolfenstein 3D game, which was the first FPS ever. It explores ray-casting. The goal is to make a dynamic view inside a maze.<br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/rafaelabdm/cub3D?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/rafaelabdm/cub3D?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/rafaelabdm/cub3D?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/rafaelabdm/cub3D?color=green" />
</p>

<p align="center">
<SUB>Por Rafaela Bustamante e Raphael dos Santos Esteves, cadetes na 42 São Paulo.</SUB>
</p>

---

<h2>🧀‍ꡌ‍ꡙ‍ꡚ‍🐁 Sobre o projeto</h2>

> _Rays every where!_
<p>
Nesse projeto criamos nosso próprio raycast! O propósito dele é melhorar nossas habilidades gráficas usando esse conceito.<br>
O raycast é muito otimizado e isso faz com que ele funcione consumindo poucos recursos do computador, o que abriu caminho para 
o jogo Wolfenstein 3D ser o primeiro FPS (visão em primeira pessoa) do mundo.<br>
O desafio desse projeto se encontra no uso da biblioteca gráfica MiniLibX e no entendimento da matemática para gerar os frames em '3D'.<br>
</p>

<h2>☄ Um pouco sobre o código</h2>

<p>
O código foi dividido entre as etapas de inicialização (cub_init) e execução (cub_run).<br><br>
<b>INICIALIZAÇÃO:</b> Nessa parte inicializavamos as estruturas, pegávamos as informações dos arquivos de configuração (.cub) e em seguida 
as validávamos. Passado essa etapa com sucesso, vamos para a execução.<br><br>
<b>EXECUÇÃO:</b> Pegado todas as informações necessárias (e já verificadas) para gerar o labirinto, comecávamos a etapa de raycast.<br>
A ideia básica por tras desse conceito está em lançar raios a partir de um ponto (jogador) até esses raios atingirem paredes. Com isso fazemos
uma verificação de qual parede o jogador está vendo. Essa verificação é feita através da distância do jogador até o ponto de cruzamento do raio 
e a parede. Essa distãncia também nos dá a altura da parede. (se você não aprendeu pitágoras até agora, chegou seu momento). Feito a escolha da 
parede (vertical ou horizontal), vem a escolha da textura. Essa verificação é feita através do ângulo do raio lançado, assim sabemos para qual 
direção cardial (N,S,E,W) o jogador está olhando.<br><br>
Depois de todas essas etapas, montamos a imagem e a jogamos na tela. Isso se repete frame a frame.<br>
</p>

<h2>🗺️MAPAS (arquivos de configuração):</h2>
<p>
Os mapas são os arquivos de configuração (<arquivo>.cub). Eles precisam ser formatados da seguinte maneira:<br>
TEXTURAS: elas devem indicar o sentido (NO, SO, WE, EA) e a textura que querem usar para aquela parede.<br>
</p>

```
NO ./textures/default_NO.xpm
SO ./textures/default_SO.xpm
WE./textures/default_WE.xpm
EA ./textures/default_EA.xpm
```

CORES: seguem o padrão RGB, você pode passar as cores do chão (F) e teto (C) na seguinte formatação:<br>

```
C 42,42,42
F 142,142,142
```

MAPA: devem estar sempre cercados de paredes e os únicos caractéres válidos são 1 (parede), 0 (caminho válido), 
NSWE (posição do jogador e a orientação para qual ele começa olhando), e ' ' (espaço);<br>

exemplo:
```
        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010000001
11000000110101011100000010001
10000000000000001100000010001
10000000000000000001010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

<h2>💻 COMO USAR:</h2>

<p>
<b>Comando do terminal:</b> <TT> ./cub3D maps/arquivo_de_configuração.cub</TT> ;<br>
<SUB>Você precisa da biblioteca da externa <i>MiniLibX</i> instalada.</SUB><br>
<SUB>As texturas precisam ser 64x64 pixels.</SUB>
</p>
