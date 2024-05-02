# CP2-Edge

Projeto de Monitoramento Ambiental
Descrição
Este projeto consiste em um sistema de monitoramento ambiental que utiliza diversos sensores para medir e exibir informações sobre temperatura, umidade e luminosidade. O sistema é composto por um microcontrolador Arduino, um sensor de luminosidade LDR, um sensor de temperatura e umidade DHT, e um display LCD para exibição das informações.

Componentes Utilizados
Arduino Uno (ou similar)
Sensor de Luminosidade LDR
Sensor de Temperatura e Umidade DHT
Display LCD 16x2
Resistores e componentes elétricos básicos
Funcionamento
O sistema realiza as seguintes operações:

Inicialização: Ao ligar o sistema, uma tela de inicialização é exibida, seguida por uma mensagem de boas-vindas.
Monitoramento: O sistema faz a leitura dos sensores de luminosidade e temperatura/umidade em intervalos regulares.
Exibição: As informações lidas são exibidas no display LCD em tempo real. Isso inclui a temperatura em graus Celsius, a umidade em percentual, e a luminosidade em percentual.
Alertas: O sistema pode acionar alertas sonoros e visuais caso alguma condição pré-definida seja atendida. Por exemplo, se a luminosidade estiver abaixo de um certo limite ou se a temperatura ultrapassar um valor máximo.
Instalação e Configuração
Conecte todos os componentes conforme o esquema elétrico fornecido.
Carregue o código fonte fornecido no Arduino IDE.
Compile e faça o upload do código para o Arduino.
Certifique-se de que os sensores estão corretamente calibrados e ajustados conforme as necessidades do ambiente de monitoramento.
Contribuições e Melhorias
Contribuições para melhorias deste projeto são bem-vindas. Sinta-se à vontade para enviar pull requests com correções de bugs, otimizações de código ou novos recursos.
