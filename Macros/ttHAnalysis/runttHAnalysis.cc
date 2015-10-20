void runttHAnalysis(const std::string MulticrabDir = "", 
                    const std::string SampleName = "", 
                    const std::string text = "",
                    const int MaxEvents = -1)
{
  gSystem->CompileMacro("ttHAnalysis.C");
  const std::string absolutePath = "/home/athermw/Research/rootFiles";
  ttHAnalysis macro(absolutePath + "/" + MulticrabDir,SampleName, text, MaxEvents);
  macro.Loop();
}
