---
hide:
  - navigation
---

# FF5M / FF5M Pro / AD5X Z-Mod

<img width="698" height="291" alt="logo zmod" src="https://github.com/user-attachments/assets/5e26413b-c9a2-49f2-b9b8-5ecde709c521" />

[LINK do Z-Mod disponível neste link ->](https://zmod.link/link/)

### **Z-Mod para FlashForge AD5M/PRO/AD5X: controle total da sua impressora**

Parabéns por sua compra de uma impressora FlashForge! O firmware nativo é ótimo para começar, mas se você quiser desbloquear o **potencial completo** do seu dispositivo, o Z-Mod é uma solução poderosa e gratuita que transforma sua impressora de "personalizada" em "profissional".

### O que é o Z-Mod?

O Z-Mod é um firmware personalizado (modificação) que é instalado sobre o software nativo. Ele não o substitui, mas o **amplia** adicionando um grande número de recursos conhecidos de impressoras avançadas, mantendo todos os benefícios e a conveniência da interface nativa.

> **Por que "Z-Mod"?** O autor é conhecido pelo apelido [zserg](https://zserg.ru/) há mais de 20 anos. Quando chegou a hora de nomear o mod, a resposta foi óbvia: primeira letra do apelido mais "mod". Sem significado oculto, sem simbolismo — é realmente tão simples quanto parece.

---

### Principais vantagens do Z-Mod sobre o firmware nativo

Veja o que você obtém ao instalar o Z-Mod:

#### 1. Controle remoto completo

**Firmware nativo:** Você pode enviar arquivos por Wi-Fi, mas somente por meio do Orca FF ou do aplicativo FlashForge (que pode não estar disponível devido a problemas no servidor).
**Z-Mod:** Você obtém **controle total do seu navegador** no seu computador ou telefone.

    * Fluidd / Mainsail:** Interfaces da Web fáceis de usar, nas quais você vê todas as informações de impressão, temperatura, controla a velocidade dos ventiladores, move os eixos e tem acesso total ao console de comando.
    * Envio de arquivos via "Octo/Klipper":** Integração com o Orca Slicer e outros fatiadores para envio direto de código G.
    * Acesso à interface da Web da impressora via serviço de nuvem da Internet** [zmod.link](https://zmod.link)
    * **Notificação para o Telegram e mais de 100 outros serviços** [plugin notify](https://github.com/ghzserg/notify/blob/main/Readme_ru.md)

#### 2. Sistemas avançados de calibração e nivelamento

**Firmware nativo:** Nivelamento automático básico da mesa (ABL).
**Z-Mod:**

    * **Nivelamento adaptativo (KAMP):** A impressora não constrói um mapa de irregularidades da mesa em toda a área, mas somente na área em que seu modelo está localizado. Isso **economiza tempo** e melhora a precisão.
    * Calibração PID:** Ajuste fino das configurações de temperatura da extrusora e da mesa para obter uma temperatura estável sem flutuações.
    * Redutor de vibração (Input Shaper):** Analisa e compensa as vibrações do corpo, permitindo que você imprima **mais rápido e sem "anéis "** nos modelos.
    * Espectrograma da correia:** Analisa a condição das correias da impressora para manutenção preventiva.
    * Ajuste do parafuso da mesa:** Permite que você nivele a mesa em 10 minutos.

#### 3. Recursos inteligentes para confiabilidade

* Firmware:** Sensores básicos de terminação de filamento. Não há controle sobre o firmware e os arquivos transferidos, o que resulta em falhas de impressão.
**Z-Mod:**

    * Controle de bico: O sistema, usando células de carga, pode detectar que o bico atingiu uma peça impressa ou uma mesa e **interromper automaticamente a impressão**, evitando quebras.
    * Recuperação de falha de energia:** A impressora se lembrará do local da falha de energia e poderá continuar a imprimir depois que a energia for ligada.
    * Controle de firmware: A impressora pode corromper arquivos por si só, portanto, pode controlar tanto os arquivos de firmware nativos quanto os arquivos Z-Mod.
    * Controle de arquivos transferidos para a impressora:** Controle de soma MD5 ao transferir arquivos.

#### 4. Manuseio flexível de filamentos (especialmente para a AD5X)

**Firmware nativo:** Controle da bobina por meio do menu padrão.
**Z-Mod (para AD5X):**

    * Menu inteligente de cores (`COLOR`):** Seleção visual de bobina, mudança de cor e tipo de plástico diretamente da interface da Web.
    * ** **"Endless Spool Mode":** Se você tiver vários carretéis do mesmo plástico, a impressora passará automaticamente para o próximo quando o primeiro acabar.
    * Configuração de desperdício fino:** Você pode reduzir a quantidade de plástico que a impressora purga ao trocar de cor, economizando material.

#### 5. Ecossistema e integração

* **Firmware nativo:**Sistema fechado.
**Z-Mod:**
    * Telegram-bot:** Receba notificações sobre o início e o fim da impressão, fotos da câmera diretamente no Telegram.
    * Suporte a plugins:** Instale plugins adicionais (como o `bambufy` para melhor compatibilidade com o Bambu Studio).
    * Câmera alternativa: ajuste a resolução, o FPS e reduza a carga de memória para uma transmissão estável.
    * Reprodução de música:** Reproduz música quando a impressão começa ou termina

#### 6. Otimização e controle

* **Firmware nativo:**Configurações limitadas.
**Z-Mod:**
    * Desativar tela nativa: Para economizar RAM (relevante para modelos AD5M com 128 MB).
    * GuppyScreen:** Uma interface alternativa para a tela da impressora com recursos avançados.
    * HelixScreen:** Uma interface alternativa para a tela da impressora com recursos avançados.
    * Visualizador de logs: informações completas sobre todos os processos para diagnosticar problemas.
    * Retração de firmware: configure a retração diretamente durante a impressão, sem necessidade de refazer o corte.
    * Acesso total ao ROOT:** O acesso total à impressora é sempre possível

#### 7. Klipper 13

**Firmware nativo:** O AD5M usa o Klipper 11 desatualizado, que tem muitos erros (E0011, E0017, exclusão de objeto incorreta, SCV incorreta, recuperação de impressão incorreta etc.).
**Z-Mod:**
    * Corrige erros no Klipper nativo e permite usar uma versão mais moderna

---

### Currículo: para quem é o Z-Mod?

| Se você… | O Z-Mod lhe dará… |
| :--- | :--- |
| **Iniciante** | Controle remoto fácil e calibrações automáticas para qualidade consistente na primeira tentativa. |
| **Entusiasta** | Controle total sobre todos os aspectos da impressão, com recursos avançados para ajuste fino e experimentos de velocidade. |
| **Proprietário do AD5X** | O máximo em controle de impressão multicolorida e custos reduzidos de filamento. |

O **Z-Mod não substitui o firmware nativo**, mas torna-se um complemento que lhe dá a **escolha** de trabalhar da maneira antiga, por meio da tela, ou usar todas as ferramentas modernas de impressão 3D. Essa é a próxima etapa lógica para qualquer proprietário de FlashForge que deseja obter o máximo de sua impressora.

!!! danger
    *Se quiser instalar este mod no seu AD5M (Pro) / [AD5X](/pt/AD5X/), esteja ciente de que você corre o risco de perder a garantia ou danificar a impressora. Prossiga por sua própria conta e risco se quiser experimentar este mod!
    
    Se você não sabe o que é isso, não entende por que precisa da página da Web do klipper ou está satisfeito com o estoque, não instale esse mod. Para todos os outros - **leia as instruções completas**!
    
    Você instalou o mod. Você não quer entender nada - imprima como fez. Você não precisa ajustar ou alterar absolutamente nada. Decidiu que está pronto para seguir em frente - você segue em frente - lendo a [documentação](https://ghzserg.github.io/).

## Antes de começar

#### Você não precisa instalar o mod se precisar apenas corrigir os seguintes problemas no firmware nativo

Esses recursos são portados para o firmware padrão:

1. Eu quero o Klipper. (O Klipper já está na impressora, mas não há interface da Web)
2. [Instalar root](/pt/Native_FW/#root)
3. corrigir o bug [E0011](/en/Global/#fix_e0011)
4. corrigir o bug [E0017](/pt/Global/#fix_e0017)
5. [Desativar atualizações de impressora/telemetria/China_cloud](/pt/Global/#china_cloud)
6. [Retornar a impressora às configurações de fábrica](/pt/Setup/#return-printer-to-factory-settings-needed-for-installation-mod)
7. [Re-flash FF5M to FF5MPro](/pt/Native_FW/#re-flash-5m-to-5mpro)
8. [FF5MPro para FF5M](/pt/Native_FW/#translate-5mpro-to-5m)



### Compatibilidade
Instalado em uma versão limpa:

- FF5M/FF5MPro **pelo menos 2.7.5** (2.7.5, 2.7.6, 2.7.7, 2.7.8, 2.7.9, 3.1.3, 3.1.4, 3.1.5, 3.1.9, **3.2.3**, 3.2.4, 3.2.5, 3.2.6, 3.2.7, 5.0.3)
- [AD5X](/pt/AD5X/) **somente** (1.0.2, 1.0.7, 1.0.8, 1.0.9, 1.1.1, 1.1.6, **1.1.7**, 1.1.9, 1.2.0, 1.2.1, 1.2.2, 1.2.3, 3.0.3)

O firmware nativo está disponível [aqui](/en/Native_FW/).

## Instalar/atualizar/desinstalar mods

[Instalar/Atualizar/Desinstalar Mod](/pt/Setup/)
  
## Perguntas frequentes

[Must Read](/pt/FAQ/)

## Recomendações para melhorar a estabilidade da impressora

[Leia - se algo não estiver funcionando corretamente](/en/Recomendations/)

## Plug-ins

O Z-Mod suporta [Plug-ins](/pt/Plugin/)

## Componentes utilizados

- Root baseado na implementação de [@darksimpson](https://t.me/darksimpson). Login e senha: root. [Link](https://t.me/c/2000598629/12695/186253)
- Beeper baseado na implementação de [@drmax_gc](https://t.me/drmax_gc). M300. M356 Für Elise. [Link](https://t.me/FF_5M_5M_Pro/1/333800)
- Verificação MD5 de Igor Polunovskiy incluída. [Link](https://t.me/FF_5M_5M_Pro/12695/272417)
- [GuppyScreen](https://github.com/ballaswag/guppyscreen)

O mod utiliza os desenvolvimentos do [KlipperMod](https://github.com/xblax/flashforge_ad5m_klipper_mod/), mas não é sua continuação ou desenvolvimento, e também não é compatível com ele nem em sintaxe de macros nem binariamente.

## Ajuda ao desenvolvimento

Como as pessoas pediram, eu aceito doações, mas lembre-se de que estou trabalhando no Z-Mod por diversão, não por dinheiro. Não aceitarei doações para trabalhar em bugs ou recursos específicos.

As formas de apoio disponíveis podem ser encontradas em uma [página] separada (/en/Sponsor/)
