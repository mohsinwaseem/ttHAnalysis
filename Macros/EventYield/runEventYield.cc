void runEventYield(const std::string MulticrabDir = "", 
                    const std::string SampleName = "", 
                    const std::string text = "",
                    const int MaxEvents = -1)
{
  gSystem->CompileMacro("EventYield.C");
  const std::string absolutePath = "/home/athermw/Research/rootFiles";
  EventYield macro(absolutePath + "/" + MulticrabDir,SampleName, text, MaxEvents);
  macro.Loop();
}
