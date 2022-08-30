import os
import configparser

def main():
    with open('full_template.cpp', 'r') as template_file:
        lines = template_file.read()

    for prob_name in prob_list:
        with open(folder_name + "//" + prob_name + "sol.cpp", 'w') as sol_file:
            sol_file.write(lines)
        
        with open(folder_name + "//" + prob_name + "in.txt", 'w') as in_file:
            pass

if __name__ == "__main__":
    config = configparser.ConfigParser()
    config.read("config_gen.py")

    contest = config["CONTEST"]
    folder_name = contest["folder_name"]
    folder_name = os.path.abspath(folder_name)
    prob_list = eval(contest["prob_list"])

    if not os.path.isdir(folder_name):
        os.makedirs(folder_name)

    main()