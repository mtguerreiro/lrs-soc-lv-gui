## Instructions to convert the LabVIEW VI report to a Latex document

## Prerequisites
- Install LabVIEW 2019 or later
- Install Pandoc

## Steps
1. Open Report_generator.vi in LabVIEW and run the VI to generate the report as html file.
2. Then to convert an HTML file to LaTeX using Pandoc, you can use the following command in your terminal:

```bash
 pandoc -s repot_generated.html -o Report_laview_generated.tex
```
Replace report_generated.html with the path to your HTML file and Report_labview_generated.tex with the desired name for the output LaTeX file.

Here's what each part of the command does:

- -s: This option tells Pandoc to produce a standalone LaTeX document. This means Pandoc will include all necessary headers and formatting to create a complete LaTeX document.

- input.html: This is the path to your HTML file that you want to convert.

- -o output.tex: This specifies the output file name and format. In this case, the output file will be named output.tex and will be in LaTeX format.

After running this command, Pandoc will convert the HTML file to LaTeX and save the result in the specified output file. You can then open the LaTeX file in your preferred text editor or compile it using a LaTeX compiler to generate a PDF.