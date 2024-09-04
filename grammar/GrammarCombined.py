global terminals, variables, varConv, termConv, k, m

variables = [chr(i) for i in range(65,  90)] + [f'{chr(i)}\'' for i in range(65,  90)]
varConv   = dict()
terminals = [chr(i) for i in range(97, 123)] + [str(i) for i in range(10)] + ['@', '#', '?', '%']
terminals.remove('e')
termConv  = dict()
k = 0
m = 0

def convertVariable(w):
    global terminals, variables, varConv, termConv, k, m
    if (w not in varConv):
        varConv[w] = variables[k]
        k = k + 1
    return varConv[w]

def convertTerminal(w):
    global terminals, variables, varConv, termConv, k, m
    
    if (w not in termConv):
        if (len(w) > 1):
            termConv[w] = terminals[m]
            m = m + 1
        else:
            if (w == '<'):
                termConv[w] = '{'
            elif (w == '>'):
                termConv[w] = '}'
            else:
                termConv[w] = w
    return termConv[w]


def parteSymbol(w):
    if (w[0].isupper()):
        return convertVariable(w)
    else:
        return convertTerminal(w)


def process_line(line:str):
    if not line.strip():
        return None
    left_side, right_side = line.split("->")
    left_side = left_side.strip()
    # right_side = right_side.replace(" ", "").strip()
    right_side = [w.strip() for w in right_side.split(" ")]
    while('' in right_side):
        right_side.remove('')
    # print(right_side)
    right_side = [parteSymbol(w) for w in right_side]
    if len(right_side) < 1:
        right_side = ["\'\'"]
    return f"{convertVariable(left_side)} -> {' '.join(right_side)}"

def process_file(input_filename, output_filename):
    with open(input_filename, 'r') as infile, open(output_filename, 'w') as outfile:
        for line in infile:
            processed_line = process_line(line)
            if processed_line:
                outfile.write(processed_line + "\n")














input_filename = 'GrammarMod.txt'
output_filename = 'GrammarCompactedMod.txt'
process_file(input_filename, output_filename)
for w in varConv:
    print(f"{w:25s} {varConv[w]:10s}")
print("---------------------------")
# print("Fator                     W")
for w in termConv:
    print(f"{w:25s} {termConv[w]:10s}")