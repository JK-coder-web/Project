import Child1 from "./components/Child1";
import Child2 from "./components/Child2";
import Child3 from "./components/Child3";
import FirstContextProvider from "./FirstContext";

function App() {
  return (
    <>
      <FirstContextProvider>
        <Child1 />
        <Child2 />
        <Child3 />
      </FirstContextProvider>
    </>
  );
}

export default App;
