# Projeto Arduino: Sensor de Estacionamento com Alarme

## Descrição
Este projeto implementa um sistema de assistência para estacionamento utilizando um Arduino e um sensor ultrassônico. Quando o sensor detecta que o veículo está próximo de um obstáculo, um alarme (buzzer) é acionado. Este projeto demonstra como utilizar um sensor ultrassônico para medir distâncias e acionar um alarme sonoro.

## Componentes Utilizados
- Arduino Uno
- Sensor Ultrassônico (HC-SR04)
- Buzzer
- Resistores
- Jumpers
- Protoboard

## Funcionamento
1. **Configuração Inicial:**
   - No `setup()`, os pinos digitais do Arduino são configurados para comunicação com o sensor ultrassônico e o buzzer.
2. **Medição da Distância:**
   - O sensor ultrassônico mede a distância entre o veículo e o obstáculo.
   - O Arduino processa os dados para determinar a proximidade do obstáculo.
3. **Acionamento do Alarme:**
   - Se a distância medida estiver abaixo de um valor pré-determinado, o Arduino aciona o buzzer para alertar o motorista.

## Como Usar
1. Conecte o sensor ultrassônico e o buzzer ao Arduino conforme o esquema de ligação fornecido.
2. Faça o upload do código para o Arduino usando a IDE Arduino.
3. Teste o sistema aproximando um objeto do sensor e observe o acionamento do alarme.

## Ajustes e Personalizações
- **Distância de Alarme:** A distância mínima para acionar o alarme pode ser ajustada no código conforme necessário.
- **Tipos de Alarme:** É possível personalizar o tipo de alarme (por exemplo, frequência do som) para diferentes distâncias.

## Contribuição
Contribuições são bem-vindas! Sinta-se à vontade para abrir um issue ou enviar um pull request.
