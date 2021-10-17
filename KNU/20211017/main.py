import argparse
import IOsample # found in IOSample.py for processing input-1
import command  # found in command.py for processing input-2

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='-e filename -c filename')

    parser.add_argument('-e', help='input file that includes i/o samples', default='input1.txt')
    parser.add_argument('-c', help='input file that describes usable commands', default='input2-command.txt')

    args = parser.parse_args()
    #print(args)
    
    ios = IOsample.read_file(args.e)	# parse io samples
    #ios.toString()   

    expressions = command.read_file(args.c)     # parse expressions

    '''
    for i in expressions:
        print(str(i)+':')
        print(expressions[i].toString())
        print()
    '''
    
    tree = command.deepcopyExpression(expressions['e0'], 0, 20) # make tree
    #print(tree.toString())
 
    command.initializeCodeGenerationSequence()
    code = command.generateNextDistinctCode(tree)
    while code != None:        
        result = IOsample.validateCode(ios, code)
        if result[0] > 0 and result[1] == 0:
            print("---- code #", command.distinctCodeCount, "----") 
            print(code)
            print()
        code = command.generateNextDistinctCode(tree)        
        
    print("A total of", command.distinctCodeCount, "distinct codes explored")

