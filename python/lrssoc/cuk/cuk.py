"""
Module ``cuk``
==============


"""
import lrssoc
import numpy as np
import matplotlib.pyplot as plt

class Commands:
    """
    """
    def __init__(self):
        self.blink = 0
        self.adc_en = 1
        self.adc_config = 2
        self.pwm_config = 3


class Cuk:
    """

    Parameters
    ----------

    Raises
    ------

    Attributes
    ----------
        
    """
    def __init__(self, cs_id, comm, comm_settings, tr_id=0):

        self._cs_id = 0

        self._ocp_if = lrssoc.ocp.iface.Interface(comm_type=comm, settings=comm_settings)

        self._ctl_if = lrssoc.cuk.cuk_controller.Controller(ocp_if=self._ocp_if, cs_id=cs_id)

        self._hw_if = lrssoc.cuk.cuk_hw.Hw(ocp_if=self._ocp_if, cs_id=cs_id)

        self._tr_if = lrssoc.cuk.cuk_trace.Trace(ocp_if=self._ocp_if, tr_id=tr_id)
        self._tr_id = tr_id

        self._plot = lrssoc.cuk.cuk_plot.Plot()

    
    def control_sys_enable(self):
        """
        """
        status, = self._ocp_if.cs_enable( self._cs_id )
        if status != 0:
            return (-1, status)

        return (0,)
        

    def control_sys_disable(self):
        """
        """
        status, = self._ocp_if.cs_disable( self._cs_id )
        if status != 0:
            return (-1, status)
        
        return (0,)


    def control_sys_status(self):
        """
        """
        cmdstatus, status = self._ocp_if.cs_status( self._cs_id )
        if cmdstatus != 0 :
            print('Error getting status')
            return (-1, cmd_status)

        return (0, status)
        

    def controller_disable(self):
        """
        """
        status, = self._ctl_if.set( 0 )
        if status != 0:
            return (-1, status)

        return (0,)

    
    def controller_enable(self, controller, reset=True):
        """
        """
        if reset is True:
            status, = self._ctl_if.reset( controller )
            if status < 0:
                return (-1, status)
        
        status, = self._ctl_if.set( controller )
        if status < 0:
            return (-1, status)      

        return (0,)


    def controller_set_params(self, controller, params):
        """
        """
        status, new_params = self._ctl_if.get_params( controller )
        if status < 0:
            return (-1, status)

        for param, val in params.items():
            if param in new_params:
                new_params[param] = val
                
        status, = self._ctl_if.set_params( controller, new_params )
        if status < 0:
            return (-1, status)      

        return (0,)


    def controller_get(self):
        """
        """
        status, controller = self._ctl_if.get()
        if status != 0:
            return (-1, status)

        return (0, controller)


    def controller_get_params(self, controller):
        """
        """
        status, params = self._ctl_if.get_params(controller)
        if status != 0:
            return (-1, status)

        return (0, params)


    def controller_set_ref(self, ref):
        """
        """
        status = self._ctl_if.set_ref(ref)
        if status[0] != 0:
            return (-1, status)

        return (0,)        


    def controller_get_ref(self):
        """
        """
        status, ref = self._ctl_if.get_ref()
        if status != 0:
            return (-1, status)

        return (0, ref)

    
    def trace_read(self):
        """
        """
        status, (traces, trace_data) = self._tr_if.read()
        if status != 0:
            return (-1, status)

        status, freq = self._hw_if.get_pwm_frequency()
        if status != 0:
            return (-1, status)

        t = 1 / freq * np.arange( len(trace_data[0]) )
        trace_data = np.array(trace_data).T
        
        return (0, (traces, trace_data, t))


    def trace_reset(self):
        """
        """
        status, = self._tr_if.reset()
        if status != 0:
            return (-1, status)

        return (0,)


    def trace_set_size(self, size):
        """
        """
        status = self._tr_if.set_size(size)
        if status[0] != 0:
            return (-1, status[0])

        return (0,)


    def trace_get_size(self):
        """
        """
        status, size = self._tr_if.get_size()
        if status != 0:
            return (-1, status)

        return (0, size)


    def plot(self, data, t=None, ax=None):
        self._plot.measurements(data, t)

    def plot_energy(self, data, t=None, ax=None):
        self._plot.energy(data, t)

    def plot_live(self, dt):

        status, freq = self._hw_if.get_pwm_frequency()
        if status != 0:
            return (-1, status)

        n_samples = round(dt * freq)

        self.trace_set_size(n_samples)

        t = 1 / freq * np.arange( n_samples )

        fig, axes = plt.subplots(nrows=2, ncols=2)
        fig.set_size_inches(10, 6)

        while True:
            status, (traces, data, t) = self.trace_read()
            self._plot.measurements(data, t, fig=fig)
            plt.pause(dt)
            self.trace_reset()

        
