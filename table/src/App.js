import React,  { useState, useEffect } from 'react';
import Table from './components/Table/Table';
import { browserName, browserVersion } from "react-device-detect";


function App() {

    return (
        <div className='App'>
            { browserName === "Chrome" && browserVersion >= 89 ?
                <Table /> :
                <h3>Unsupported Browser. Use Chrome latest version</h3>
            }
        </div>
    );
}

export default App;
