void runWZStudies(const std::string MulticrabDir = "", 
                    const std::string SampleName = "", 
                    const std::string text = "",
                    const int MaxEvents = -1)
{
  gSystem->CompileMacro("WZStudies.C");
  const std::string absolutePath = "/home/athermw/Research/rootFiles";
  WZStudies macro(absolutePath + "/" + MulticrabDir,SampleName, text, MaxEvents);
  macro.Loop();
}
