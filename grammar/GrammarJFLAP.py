def process_line(line):
    if not line.strip():
        return None
    left_side, right_side = line.split("->")
    left_side = left_side.strip()
    right_side = right_side.replace(" ", "").strip()
    return (f'\t<production>&#13;\n\t\t<left>{left_side}</left>&#13;\n\t\t' +
             (f'<right>{right_side}</right>&#13;' if right_side != '' else '<right/>&#13;') + 
             '\n\t</production>&#13;')

def process_file(input_filename, output_filename):
    with open(input_filename, 'r') as infile, open(output_filename, 'w') as outfile:
        outfile.write(
            "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?><!--Created with JFLAP 7.1.--><structure>&#13;\n" +
            "\t<type>grammar</type>&#13;\n" + "\t<!--The list of productions.-->&#13;\n"
    )
        for line in infile:
            processed_line = process_line(line)
            if processed_line:
                outfile.write(processed_line + "\n")
        outfile.write("</structure>")

# Exemplo de uso:
input_filename  = 'GrammarCompactedMod.txt'
output_filename = 'GrammarTransformedMod.jff'
process_file(input_filename, output_filename)