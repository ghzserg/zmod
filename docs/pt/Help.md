# Como entrar em contato com o suporte ao desenvolvedor

Abra o bot do telegrama [@zmod_help_bot](http://t.me/zmod_help_bot) e faça sua pergunta a ele, pois ele conhece toda a documentação.

1. [Atualize o Z-Mod e todos os plug-ins para a versão mais recente](/en/Setup/#update-mod)
2. Traduza o mod para o russo ```LANG LANG=ru```.
3. indique claramente o problema. Telas, fotos, descrição de texto.
4. Chame [CLEAR_EMMC](/pt/System/#clear_emmc) para limpar os registros
5. **Deve desligar a impressora**
6. Ligue a impressora
7. Gerar um problema
8. Execute [TAR_CONFIG](/pt/Zmod/#tar_config) - salve os arquivos de registro
9. Poste uma mensagem com a descrição e o arquivo `config.tar.gz`
10. [Adicionar mensagem de erro](https://github.com/ghzserg/zmod/issues)

Se não for possível executar `TAR_CONFIG`:

- Baixe [log](/pt/Native_FW/#log) para um pendrive.
- Copie do pendrive o arquivo `config-1.6.6-28.tar.gz`, onde 1.6.6-28 é a versão atual do mod

Ou conecte-se à impressora via SSH:

AD5M/AD5MPro:

```
chroot /data/.mod/.zmod/
/opt/config/mod/.shell/tar_config.sh
```

AD5X:

```
chroot /usr/data/.mod/.zmod/
/opt/config/mod/.shell/tar_config.sh
```

## Por que solicito tickets - uma explicação "token"

Imagine que sua impressora é uma máquina.
E eu sou um mecânico em uma enorme oficina onde conserto centenas de carros diferentes ao mesmo tempo.

Você chega e grita:
> "Meu carro não anda!"

E eu tenho que começar com uma pergunta simples:
> "Que tipo de carro você tem - marca, modelo, ano de fabricação?"

### Por que é importante desmontá-lo peça por peça

Nossa "frota" tem **mais de 100 configurações exclusivas**. Apenas o básico:

- **3 fabricantes diferentes**:

  FF5M, FF5M Pro, AD5X

- **3 versões do "mecanismo" (Klipper)**:

  11, 12, 13

- **2 arquiteturas de processador**:

  ARM e MIPS

- Opções de salão**:

    - com tela nativa

      - com GuppyScreen

      - com HelixScreen

      - sem tela

- Duas interfaces de controle principais**:

  Fluidd e Mainsail

- Diferentes maneiras de enviar tarefas para impressão**:

  via tela nativa, Guppy, OrcaSlicer (protocolo FF, protocolo Klipper, etc.)

- "Opções" adicionais (plug-ins)**:

  `nopoop`, `recommend`, `bambufy`, `g28_tenz`, `timelapse`, `notify` e outros

- **Sensores e periféricos**:

  Sensor de filamento, sensor de movimento, IFS, etc.

E também há casos em que o proprietário **reparou algo sob o capô**, encheu de "combustível desconhecido" (firmware antigo, mods de terceiros) ou leu conselhos de IA, **nunca viu sua impressora específica**.

#### Conclusão.

Quando você escreve apenas **"não está funcionando "**, eu gasto **horas** apenas para descobrir o que é:

- Qual é o modelo que você tem?
- Qual firmware/versão do Klipper?
- Com ou sem tela?
- Qual slicer e configurações?
- Quais plug-ins estão ativados?

Isso é **ineficiente**, **atrasa a ajuda** e **incomoda todo mundo**.

---

## Como "levar seu carro para manutenção" corretamente - instruções sobre como criar um tíquete

Para que eu **não adivinhe, mas o ajude imediatamente**, faça tudo de acordo com a lista de verificação:

### 1. **Atualize para a versão mais recente**
> Siga as [instruções oficiais de atualização](/en/Setup/#upgrade-mod).

### 2. **Instalar o idioma russo**
> Execute no console:

> ```bash
> LANG LANG=ru
> ```

### 3. **Descreva o problema de forma clara e específica**
> ❌ Ruim: _"Não funciona"_

> ✅ Bom:

> _"Depois de atualizar o Z-Mod para a versão X.Y.Z, ao pressionar "Imprimir" na tela nativa:

> > - a mesa esquenta,

> - a extrusora NÃO aquece,

> - a temperatura da tela é 0°C,

> - a impressão é simplesmente cancelada após 2 minutos."_

> 🔹 Anexe **capturas de tela dos erros**, **fotos**,

> 🔹 Descreva a **sequência de ação**,

> Anexe o **arquivo que está imprimindo** (pode haver um problema no código G!).

### 4. **Faça um teste de diagnóstico completo**
> Realize-o estritamente na ordem:
> 1. `CLEAR_EMMC` - limpa os registros antigos

> 2. **Desconecte a impressora completamente** → Aguarde 10 segundos.

> 3. Ligue a impressora

> 4. **Reproduza o problema** (comece a imprimir, pressione o botão - causa o erro)

> 5. Execute `TAR_CONFIG` - isso criará um arquivo `config.tar.gz` com todos os registros

### 5. **Registre o tíquete corretamente**
> - Vá para [Issues page](https://github.com/ghzserg/zmod/issues)

> - Crie **uma** mensagem

> - Nela:

> - Uma descrição compreensível (item 3),

> - **deve anexar `config.tar.gz`**,

> - anexar **G-code** se o problema ocorrer ao imprimir um arquivo específico.

> ⚠️ Sem o `config.tar.gz` não há diagnóstico - é como fazer um exame de sangue sem sangue.

---

## O que essa abordagem faz?

Você para de gritar: "O carro não está funcionando".

e começa a trazê-lo para mim:

> 🚗 **Modelo específico**,

> 📋 **Registro de mau funcionamento**,

> 📊 **Resultados de diagnóstico**.

E então eu posso começar a **consertar - imediatamente, sem adivinhações**.

---

Obrigado pela compreensão e por respeitar o tempo das outras pessoas.

Não se trata de burocracia - é a única maneira de tornar o suporte **rápido e eficiente**.
